#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <ctime>

using namespace std;
using namespace cv;

double similarityCheck(Mat m1, Mat m2, int threshold);
Mat getBackgroundGroundTruthGray1(String fileName);
Mat getBackgroundGroundTruthGray2(String fileName);
Mat getBackgroundGroundTruth1Colored(String fileName);

int main(int argc, char **argv){


	Mat truth1;
	Mat truth2;
	Mat truth1Colored;
	string fileName = "/Users/Var/Desktop/setVideo.avi";

	truth1 = getBackgroundGroundTruthGray1(fileName);
	imshow("TRUTH 1", truth1);

	truth2 = getBackgroundGroundTruthGray2(fileName);

	imshow("TRUTH 2", truth2);

	for (int t = 0; t < 256; ++t)
	cout << "t = " << t << ": " << similarityCheck(truth1, truth2, t) << endl;

	truth1Colored = getBackgroundGroundTruth1Colored(fileName);

	imshow("TRUTH 1 COLORED", truth1Colored);

	waitKey(0);


	return 0;
}
double similarityCheck(Mat m1, Mat m2, int threshold){

	int rows1 = m1.rows;
	int cols1 = m1.cols;

	int rows2 = m2.rows;
	int cols2 = m2.cols;

	if ((rows1 != rows2) || (cols1 != cols2))
		return 0.0;

	int same = 0;
	int diff = 0;

	//cout << "Similarity Test" << endl;
	// int count = 1;
	//vector<int> similarity;
	//similarity.resize(2);
	for(int row = 0; row < rows1; row++){
		for(int col = 0; col < cols1; col++){
			int pixel1 = m1.at<uchar>(row,col);
			int pixel2 = m2.at<uchar>(row,col);
			//cout << count << " value for pixel (" << row << ", " << col <<") is " <<  valuePixel << " and value for bit is " << valueBit << endl;
				if(abs( pixel1 - pixel2 ) <= threshold ){
					++same;
				}
				else{
					++diff;
				}
				//count++;
			}
	}

	//srand ( time(NULL) );
	//double similarCount = similarity.at(1);
	//double heightAndWidth = width*height;
	//cout << heightAndWidth << " and " << similarCount << endl;
	//double similarityPercentage = similarCount/heightAndWidth;
	//cout << "SIMILARITY PERCENTAGE IS: " << similarityPercentage << endl;

	return ((double) same) / ((double)(same + diff));

	/**int random = rand() % numFrames + 1;
	int random2 = rand() % numFrames + 1;
	int random3 = rand() % numFrames + 1;
	cout << random << endl;
	cout << random2 << endl;
	cout << random3 << endl;**/

}

Mat getBackgroundGroundTruthGray1(String fileName){

	cv::VideoCapture capture(fileName);
	Mat frame;

	if(!capture.isOpened()){
		return frame;
	}

	//double rate = capture.get(CV_CAP_PROP_FPS);
	//int delay = 100/rate;

	int numFrames = capture.get(CV_CAP_PROP_FRAME_COUNT);

	vector<Mat> allFrames;

	// store the video to a vector of frames
	int frameIndex = 0;

	while(frameIndex < numFrames) {
		if(!capture.read(frame))
			break;

			cvtColor(frame,frame, CV_BGR2GRAY);
			allFrames.push_back(frame);

			//int character = cv::waitKey(delay);
			//if(character == 27) {
			//	break;
			//}
			frameIndex++;
	}

	int rows = frame.rows;
	int cols = frame.cols;

	int count = 0;
	Mat displayFrame = allFrames.at(0);
	for(int row = 0; row < rows; row++){
		for(int col = 0; col < cols; col++){
			vector<int> histogramFrame;
			histogramFrame.resize(256);

			// get the frequency of a color occurring at pixel position (r,c)
			for(int i = 0; i < numFrames; i++){
				int value = allFrames.at(i).at<uchar>(row,col);
				++histogramFrame.at(value);
			}

			// store the modal value at position (r,c) to the output matrix
			int matrixElement = distance(histogramFrame.begin(), max_element(histogramFrame.begin(), histogramFrame.end()));
			displayFrame.at<uchar>(row,col) = matrixElement;
			cout << "COUNT " << count++ << " " << matrixElement << endl;
			histogramFrame.resize(256);
		}
	}
	capture.release();
	return displayFrame;
}

Mat getBackgroundGroundTruthGray2(String fileName){

	cv::VideoCapture capture(fileName);
	Mat frame;

	if(!capture.isOpened()){
		return frame;
	}

	//double rate = capture.get(CV_CAP_PROP_FPS);
	//int delay = 100/rate;

	int numFrames = capture.get(CV_CAP_PROP_FRAME_COUNT);

	vector<Mat> allFrames;

	// store the video to a vector of frames
	int frameIndex = 0;

	while(frameIndex < numFrames) {
		if(!capture.read(frame))
			break;

			cvtColor(frame,frame, CV_BGR2GRAY);
			allFrames.push_back(frame);

			//int character = cv::waitKey(delay);
			//if(character == 27) {
			//	break;
			//}
			frameIndex++;
	}

	int rows = frame.rows;
	int cols = frame.cols;

	Mat displayFrame = allFrames.at(0);
	for(int row = 0; row < rows; row++){
		for(int col = 0; col < cols; col++){
			displayFrame.at<uchar>(row,col) = 0;

			// get the frequency of a color occurring at bit position "bit" from pixel position (r,c)
			int bitChecker = 1;
			for(int bit = 0; bit < 8; bit++){
				int cntBitOne = 0;

				for (int i = 0; i < numFrames; ++i)
				{
					int value = allFrames.at(i).at<uchar>(row,col);
					if (value & bitChecker)
						++cntBitOne;
					else
						--cntBitOne;
				}
				if (cntBitOne > 0)
					displayFrame.at<uchar>(row,col) += bitChecker;

				bitChecker = bitChecker << 1;
			}
		}
	}
	capture.release();
	return displayFrame;
}

Mat getBackgroundGroundTruth1Colored(String fileName){
	cv::VideoCapture capture(fileName);
	Mat frame;

	if(!capture.isOpened()){
		return frame;
	}

	//double rate = capture.get(CV_CAP_PROP_FPS);
	//int delay = 100/rate;

	int numFrames = capture.get(CV_CAP_PROP_FRAME_COUNT);

	vector<Mat> allFrames;

	// store the video to a vector of frames
	int frameIndex = 0;

	while(frameIndex < numFrames) {
		if(!capture.read(frame))
		break;
		Mat frame2;
		frame.copyTo(frame2);
		//cvtColor(frame,frame, CV_BGR2GRAY);
		allFrames.push_back(frame2);

		//int character = cv::waitKey(delay);
		//if(character == 27) {
		//	break;
		//}
		frameIndex++;
	}

	int rows = frame.rows;
	int cols = frame.cols;

	Mat displayFrame = allFrames.at(100);

	vector<Mat> displayBands;
	Mat testFrame;
	/**split(displayFrame, displayBands);

	Mat displayBandBlue = displayBands.at(0);
	Mat displayBandGreen = displayBands.at(1);
	Mat displayBandRed = displayBands.at(2);**/

	for(int row = 0; row < rows; row++){
		for(int col = 0; col < cols; col++){


			displayFrame.copyTo(testFrame);

			vector<int> histogramFrameBlue;
			histogramFrameBlue.resize(256);
			vector<int> histogramFrameGreen;
			histogramFrameGreen.resize(256);
			vector<int> histogramFrameRed;
			histogramFrameRed.resize(256);

			// get the frequency of a color occurring at pixel position (r,c)
			for(int i = 0; i < numFrames; i++){
				vector<Mat> matBands;
				split(allFrames.at(i), matBands);

				/**Mat blueBand = matBands.at(0);
				Mat greenBand = matBands.at(1);
				Mat redBand = matBands.at(2);

				Mat_<int> blueBandInt = blueBand;
				Mat_<int> greenBandInt = greenBand;
				Mat_<int> redBandInt = redBand;

				int blueValue = blueBandInt[row][col];
				int greenValue = greenBandInt[row][col];
				int redValue = redBandInt[row][col];**/

				Mat coloredFrame = allFrames.at(i);
				int blueValue = coloredFrame.at<Vec3b>(row,col)[0];
				int greenValue = coloredFrame.at<Vec3b>(row,col)[1];
				int redValue = coloredFrame.at<Vec3b>(row,col)[2];

				//cout << "at frame " <<  i << " blue value is " << blueValue << endl;
				//cout << "at frame " <<  i << " green value is " << greenValue << endl;
				//cout << "at frame " << i << " red value is " << redValue << endl;

				//int value = allFrames.at(i).at<uchar>(row,col);
				++histogramFrameBlue.at(blueValue);
				++histogramFrameGreen.at(greenValue);
				++histogramFrameRed.at(redValue);
			}

			// store the modal value at position (r,c) to the output matrix
			int matrixElementBlue = distance(histogramFrameBlue.begin(), max_element(histogramFrameBlue.begin(), histogramFrameBlue.end()));
			testFrame.at<Vec3b>(row,col)[0] = matrixElementBlue;
			//cout << "maximum value for blue is " << matrixElementBlue << endl;
			histogramFrameBlue.resize(256);

			int matrixElementGreen = distance(histogramFrameGreen.begin(), max_element(histogramFrameGreen.begin(), histogramFrameGreen.end()));
			testFrame.at<Vec3b>(row,col)[1] = matrixElementGreen;
			//cout << "maximum value for green is " << matrixElementGreen << endl;
			histogramFrameGreen.resize(256);

			int matrixElementRed = distance(histogramFrameRed.begin(), max_element(histogramFrameRed.begin(), histogramFrameRed.end()));
			testFrame.at<Vec3b>(row,col)[2] = matrixElementRed;
			//cout << "maximum value for red is " << matrixElementRed << endl;
			histogramFrameRed.resize(256);

		}
	}
	capture.release();
	return testFrame;
}
