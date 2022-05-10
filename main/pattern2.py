import cv2
import numpy as np
import matplotlib.pyplot as plt

def onMouse(x):
    pass

def sharpening(image, val):
    sharpening_1 = np.full((val,val), -1, dtype = np.int32)
    sharpening_1[(val-1)//2,(val-1)//2] = val**(2)

    dst = cv2.filter2D(image, -1, sharpening_1)
    return dst
    
def bluring():
    global val1
    global val2
    src = cv2.imread("pic2.jpg")
    src_rs = cv2.resize(src,dsize = (460,640))
    gray = cv2.cvtColor(src_rs,cv2.COLOR_BGR2GRAY)
    
    cv2.namedWindow('Blur&Shap')
    cv2.createTrackbar('Gaussian', 'Blur&Shap', 0, 10, onMouse)
    cv2.createTrackbar('Sharpening', 'Blur&Shap', 0, 5, onMouse)

    val1 = cv2.getTrackbarPos('Gaussian', 'Blur&Shap')
    val2 = cv2.getTrackbarPos('Sharpening', 'Blur&Shap')

    while True:
        val1 = val1 * 2 + 1
        val2 = val2 * 2 + 1
        try:
            blur = cv2.GaussianBlur(gray, (val1, val1), 0)
            sharp = sharpening(blur, val2)

            cv2.imshow('Blur&Shap', blur)
            cv2.imshow('Blur&Shap', sharp)
        except:
            break
        if cv2.waitKey(10) != -1:
            break
        val1 = cv2.getTrackbarPos('Gaussian', 'Blur&Shap')
        val2 = cv2.getTrackbarPos('Sharpening', 'Blur&Shap')
    cv2.destroyAllWindows()

def findLocalMaximum(src):
    kernel = cv2.getStructuringElement(shape=cv2.MORPH_RECT,ksize=(50,50))
    dilate = cv2.dilate(src,kernel)
    localMax = (src==dilate)
    
    erode = cv2.erode(src,kernel)
    localMax2 = src>erode
    localMax &= localMax2
    points = np.argwhere(localMax == True)
    points[:,[0,1]] = points[:,[1,0]]
    
    return points


def corners_detec(image):
    res = cv2.cornerHarris(image, blockSize = 5, ksize = 3,k = 0.01)
    ret, res = cv2.threshold(np.abs(res), 0.0106, 0, cv2.THRESH_TOZERO)

    res8 = cv2.normalize(res,None,0,255,cv2.NORM_MINMAX,dtype=cv2.CV_8U)

    corners = findLocalMaximum(res)
    corners = corners.astype(np.float32,order='C')
    term_crit = (cv2.TERM_CRITERIA_MAX_ITER+cv2.TERM_CRITERIA_EPS, 100, 0.05)
    corners2 = cv2.cornerSubPix(gray, corners, (5,5), (-1,-1), term_crit)
    return corners2, res8

def dot_choice(image):
    plt.imshow(image,'gray')
    print("===============Ginput================") 
    print ("Please click")
    dot1 = (np.around(plt.ginput(2)).T).astype(np.int)

    return dot1

def print_dot(dot):
    dot_x_list, dot_y_list, dot_num_list = [], [], []

    dot_standard = dot[0,1]
    y_shape = 1
    for i in range(1, dot.size//2):
        if dot[i][1] > dot_standard + 40:
            dot_standard = dot[i][1]
            dot_num_list.append(y_shape)
            y_shape += 1
        else:
            dot_num_list.append(y_shape)

    dot_num_list.append(y_shape)
    dot_num_list = np.array([dot_num_list]).T
    dot = np.hstack((dot,dot_num_list))
    dot2 = dot[np.lexsort((dot[:, 0], dot[:, 2]))]
    
    dot_x_list = dot2[:,0].round(2)
    dot_y_list = dot2[:,1].round(2)

    x_shape =  (dot.shape[0])//y_shape
    print("===============dot shape================")
    print(y_shape,'x', x_shape)
    print("===============dot_x location================")   
    count = 0
    for i in range(y_shape):
        for j in range(x_shape):
            print(dot_x_list[count], end = '  ')
            count += 1
        print("")
    print("================dot_y location===============")   
    count = 0
    for i in range(y_shape):
        for j in range(x_shape):
            print(dot_y_list[count], end = '  ')
            count += 1
        print("")
        
# main =============================================================================
bluring()

src = cv2.imread("pic2.jpg")
gray = cv2.cvtColor(src,cv2.COLOR_BGR2GRAY)
blur = cv2.GaussianBlur(gray, (val1, val1), 0)
sharp = sharpening(blur, val2)
corners1, res = corners_detec(sharp)
print("===============num of corner1================") 
print(corners1.shape[0])
dst = src.copy()

for x,y in corners1:
    cv2.circle(dst,(x,y),30,(255,0,0),10)

plt.figure(figsize=(10,10))

imgae1=plt.subplot(1,2,1)
imgae1.set_title('1st res')
plt.axis('off')
plt.imshow(res, cmap="gray")

imgae2=plt.subplot(1,2,2)
imgae2.set_title('1st dst')
plt.axis('off')
plt.imshow(dst, cmap="gray")
dot1 = dot_choice(dst).T
plt.show()

#--------------------- RoI 지정후 새로운 corners3 얻는 지점 ---------------------
dst2 = src.copy()
dst2 = dst2[dot1[0,1]:dot1[1,1], dot1[0,0]:dot1[1,0]]

gray2 = cv2.cvtColor(dst2,cv2.COLOR_BGR2GRAY)
blur2 = cv2.GaussianBlur(gray2, (val1, val1), 0)
sharp2 = sharpening(blur2, val2)
corners2, res2 = corners_detec(sharp2)
print("===============num of corner2================") 
print(corners2.shape[0])

dst3 = src.copy()
dst3[dot1[0,1]:dot1[1,1], dot1[0,0]:dot1[1,0]] = dst2
corners2[:,0] = corners2[:,0] + dot1[0,0]
corners2[:,1] = corners2[:,1] + dot1[0,1]

print_dot(corners2)

for x,y in corners2:
    cv2.circle(dst3,(x,y),30,(255,0,0),10)


plt.figure(figsize=(10,10))

imgae1=plt.subplot(1,2,1)
imgae1.set_title('2st res')
plt.axis('off')
plt.imshow(res2, cmap="gray")

imgae2=plt.subplot(1,2,2)
imgae2.set_title('2st dst')
plt.axis('off')
plt.imshow(dst3, cmap="gray")

plt.show()
























    
