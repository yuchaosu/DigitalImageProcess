#include <opencv2\opencv.hpp>
#include<cmath>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("Img_GammaCorrection.bmp", 0); 
	imshow("Src", img);
	int row = img.rows;
	int col = img.cols;
	Mat Dst(row, col, CV_8UC1);


	//遍历整幅图像，统计个数
	for (int i = 0; i < row; i++)
	{
		uchar* p = img.ptr<uchar>(i);
		uchar* q = Dst.ptr<uchar>(i);
		for (int j = 0; j < col; j++)
		{
			q[j] = pow(p[j]/255.0,1/2.4)*255.0;
		}
	}
	imshow("Dst", Dst);
	
	imwrite("GammaCorrection.bmp", Dst);
	
	
	//直方图绘制
	//	int grayNum[256] = { 0 }; // 数组下标值等于灰度值
	////遍历整幅图像，统计个数
	//for (int i = 0; i < row; i++)
	//{
	//	for (int j = 0; j < col; j++)
	//	{
	//		grayNum[Dst.at<uchar>(i, j)] = grayNum[Dst.at<uchar>(i, j)] + 1;
	//	}
	//}



	//// 画直方图
	//double maxVal = 0;
	//int i = 0;
	//while (1)
	//{
	//	if (i > 255)
	//		break;
	//	if (grayNum[i] > maxVal)
	//		maxVal = grayNum[i];
	//	i++;
	//}

	//int bin_num = 256; // [0,255]共256个bin
	//Mat histImg(bin_num, bin_num, CV_8U, Scalar(255)); //生成白色画布(255)
	//int hpt = static_cast<int>(0.9 * bin_num);
	////每个bin就是一条垂直线
	//for (int i = 0; i < bin_num; i++) {
	//	printf("%d ", i);
	//	int binVal = grayNum[i];
	//	int intensity = static_cast<int>(binVal * hpt / maxVal);  // 个数转化为长度，同样上面的灰度值也可以转化为长度
	//	//两点之间绘制一条线
	//	line(histImg, Point(i, bin_num),       //直方图下面的点
	//		Point(i, bin_num - intensity),     //直方图上面的点
	//		Scalar::all(0));
	//}
	//imshow("histImg", histImg);
	//imwrite("DsthistImg.bmp", histImg);

	waitKey(0);
	return 0;
}