#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <ctime>
#include <time.h>

using namespace std;
using namespace cv;

double similarityCheck(Mat m1, Mat m2, int threshold);
Mat getBackgroundGroundTruthGray1(String fileName);
Mat getBackgroundGroundTruthGray2(String fileName);
Mat getBackgroundGroundTruthGrayMean(String fileName);
Mat getBackgroundGroundTruthGrayMedian(String fileName);
Mat getBackgroundGroundTruth1Colored(String fileName);
Mat getBackgroundGroundTruth2Colored(String fileName);
Mat getBackgroundGroundTruthGrayRandom(String fileName, int numSamples);
Mat getBackgroundGroundTruthGrayRandom2Levels(String fileName);
vector<int> getRandomNumbersUnique(int output, int totalFrames);
vector<int> getRandomNumbers(int output, int totalFrames);
Mat TF_L4_Image (String sourceReference);
Mat getBG (Mat frame1, Mat frame2, Mat frame3);
Mat getBackgroundGroundTruthColoredRandom(String fileName, int number);
Mat getBackgroundGroundTruthColoredRandom2Levels(String fileName);
int valueCheck(Mat m1, Mat m2, String fileName);
int matValues(Mat m1, String fileName);
int valueCheckAbs(Mat m1, Mat m2, String fileName);
vector<Mat> fileNameGetBackground(String fileName);
Mat getBackground(int numSamples, int levels);
Mat getBackgroundImage(vector<Mat> tournamentFrames, int numSamples);
vector<Mat> allFrames;
vector<Mat> tournamentFrames;

int main(int argc, char **argv){

	Mat truth1;
	Mat truth2;
	Mat truth1Colored;
	Mat truth2Colored;
	Mat truth1Level;
	Mat truthNine2Levels;
	Mat tf;
	Mat colored81;
	Mat colored2Levels;
	Mat meanTruthGray;
	Mat medianTruthGray;
	Mat mat1;

//	string fileName = "/Users/Var/Documents/Master of Science in Computer Science (School)/Thesis Docs/Meet_Crowd/Meet_Crowd_new.avi";

	string fileName = "/Users/Var/Documents/Master of Science in Computer Science (School)/Thesis Docs/Results February 2013/Videos/Teknomo_orig.mov";

	//tf = TF_L4_Image(fileName);
	//imshow("TF", tf);

	//new code test here for request
	srand (5);
	allFrames = fileNameGetBackground(fileName);

	mat1 = getBackground(9, 2);

	cout << "TEST IN MAIN" << endl;
	imshow("CRF_3,4", mat1);

	cout << "DONE" << endl;

	waitKey(0);
	return 0;

/**	int t0 = time(0);
	truth1 = getBackgroundGroundTruthGray1(fileName);
	imshow("TRUTH 1", truth1);
	//int t1 = time(0);
	//double seconds = t1-t0;
	//similarityTxt << "truth 1 seconds: " << seconds << endl;
	imwrite("TRUTH_1.jpg", truth1);
	matValues(truth1, "TRUTH1.csv");**/

	meanTruthGray = getBackgroundGroundTruthGrayMean(fileName);
	imshow("MEAN TRUTH", meanTruthGray);
	imwrite("MEAN_TRUTH.jpg", meanTruthGray);
//	matValues(meanTruthGray, "MEANTRUTH.csv");

//	valueCheck(truth1, meanTruthGray, "truth1AndMeanTruth.csv");
//	valueCheckAbs(truth1, meanTruthGray, "truth1AndMeanTruthAbs.csv");

//	int t4 = time(0);
	truth1Level = getBackgroundGroundTruthGrayRandom(fileName, 36);
	imshow("TRUTH_ONE_LEVEL", truth1Level);
	//int t5 = time(0);
	//double seconds3 = t5-t4;
	//similarityTxt << "truth 1 Level seconds: " << seconds3 << endl;
	imwrite("TRUTH_ONE_LEVEL.jpg", truth1Level);
	matValues(truth1Level, "TRUTH1LEVEL.csv");

	valueCheck(truth1, truth1Level, "truth1AndTruth1Level.csv");
//	valueCheckAbs(truth1, meanTruthGray, "truth1AndTruth1Level.csv");

	valueCheck(meanTruthGray, truth1Level, "meanTruthAndTruth1Level.csv");

//	medianTruthGray = getBackgroundGroundTruthGrayMedian(fileName);
//	imshow("MEDIAN TRUTH", medianTruthGray);
//	imwrite("MEDIAN_TRUTH.jpg", medianTruthGray);
//	matValues(medianTruthGray, "MEDIANTRUTH.csv");

//	valueCheck(truth1, medianTruthGray, "truth1AndMedianTruth.csv");
//	valueCheckAbs(truth1, medianTruthGray, "truth1AndMedianTruthAbs.csv");

//	int t2 = time(0);
//	truth2 = getBackgroundGroundTruthGray2(fileName);
//	imshow("TRUTH 2", truth2);
//	int t3 = time(0);
//	double seconds2 = t3 - t2;
//	similarityTxt << "truth 2 seconds: " << seconds2 << endl;
//	imwrite("TRUTH_2.jpg", truth2);

	//similarityTxt << "Grayscale Ground Truth 1 and Ground Truth 2" << endl;
	//for (int t = 0; t <= 10; ++t)
	//similarityTxt << "t = " << t << ": " << similarityCheck(truth1, truth2, t) << endl;**/

	/**int t10 = time(0);
	truth1Colored = getBackgroundGroundTruth1Colored(fileName);
	imshow("TRUTH 1 COLORED", truth1Colored);
	int t11 = time(0);
	double seconds6 = t11 - t10;
	similarityTxt << "truth 1 Colored seconds: " << seconds6 << endl;
	imwrite("TRUTH_1_COLORED.jpg", truth1Colored);

	int t12 = time(0);
	truth2Colored = getBackgroundGroundTruth2Colored(fileName);
	imshow("TRUTH 2 COLORED", truth2Colored);
	int t13 = time(0);
	double seconds7 = t13 - t12;
	similarityTxt << "truth 2 Colored seconds: " << seconds7 << endl;
	imwrite("TRUTH_2_COLORED.jpg", truth2Colored);**/

	/**int t14 = time(0);
	colored81 = getBackgroundGroundTruthColoredRandom(fileName,9);
	imshow("81 COLORED", colored81);
	int t15 = time(0);
	double seconds8 = t15 - t14;
	similarityTxt << "truth 2 Colored seconds: " << seconds8 << endl;
	imwrite("81_COLORED.jpg", colored81);

	int t12 = time(0);
	colored2Levels = getBackgroundGroundTruthColoredRandom2Levels(fileName);
	imshow("TRUTH COLORED 2 LEVELS", colored2Levels);
	int t13 = time(0);
	double seconds9 = t13 - t12;
	similarityTxt << "truth Colored 2 Levels seconds: " << seconds9 << endl;
	imwrite("TRUTH_COLORED_2LEVELS.jpg", colored2Levels);**/

	/**cout << "Colored" << endl;
	for (int t = 0; t < 256; ++t){
		cout << "Blue band: " << endl;
		cout << "t = " << t << ": " << similarityCheck(truth1Colored.at<Vec3b>.at(0).at(i), truth2Colored.at<Vec3b>.at(0).at(i), t) << endl;
		cout << "Green band: " << endl;
		cout << "t = " << t << ": " << similarityCheck(truth1Colored.at<Vec3b>.at(1).at(i), truth2Colored.at<Vec3b>.at(1).at(i), t) << endl;
		cout << "Red band: " << endl;
		cout << "t = " << t << ": " << similarityCheck(truth1Colored.at<Vec3b>.at(2).at(i), truth2Colored.at<Vec3b>.at(2).at(i), t) << endl;
	}

	int t4 = time(0);
	truth1Level = getBackgroundGroundTruthGrayRandom(fileName, 81);
	imshow("TRUTH_ONE_LEVEL", truth1Level);
	int t5 = time(0);
	double seconds3 = t5-t4;
	similarityTxt << "truth 1 Level seconds: " << seconds3 << endl;
	imwrite("TRUTH_ONE_LEVEL.jpg", truth1Level);

	similarityTxt << endl;
	similarityTxt << "Grayscale Ground Truth 1 and CRF 81" << endl;
	for (int t = 0; t <= 10; ++t)
	similarityTxt << "t = " << t << ": " << similarityCheck(truth1, truth81, t) << endl;

	int t6 = time(0);
	truthNine2Levels = getBackgroundGroundTruthGrayRandom2Levels(fileName);
	imshow("TRUTH9", truthNine2Levels);
	int t7 = time(0);
	double seconds4 = t7-t6;
	similarityTxt << "truth 9 2 levels seconds: " << seconds4 << endl;
	imwrite("TRUTH_9.jpg", truthNine2Levels);

	similarityTxt << endl;
	similarityTxt << "Grayscale Ground Truth 1 and CRF 9,2" << endl;
	for (int t = 0; t <= 10; ++t)
	similarityTxt << "t = " << t << ": " << similarityCheck(truth1, truthNine2Levels, t) << endl;

	int t8 = time(0);
	tf = TF_L4_Image(fileName);
	imshow("TF", tf);
	int t9 = time(0);
	double seconds5 = t9-t8;
	similarityTxt << "TF seconds: " << seconds5 << endl;
	imwrite("T_F.jpg", tf);
	similarityTxt << endl;
	similarityTxt << "Grayscale Ground Truth 1 and TF" << endl;
	for (int t = 0; t <= 10; ++t)
	similarityTxt << "t = " << t << ": " << similarityCheck(truth1, tf, t) << endl;
**/
	cout << "DONE!" << endl;

	//similarityTxt.close();

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

	for(int row = 0; row < rows1; row++){
		for(int col = 0; col < cols1; col++){
			int pixel1 = m1.at<uchar>(row,col);
			int pixel2 = m2.at<uchar>(row,col);
				if(abs( pixel1 - pixel2 ) <= threshold ){
					++same;
				}
				else{
					++diff;
				}
			}
	}

	return ((double) same) / ((double)(same + diff));
}

int valueCheck(Mat m1, Mat m2, String fileName){

	int rows1 = m1.rows;
	int cols1 = m1.cols;

	int rows2 = m2.rows;
	int cols2 = m2.cols;

	if ((rows1 != rows2) || (cols1 != cols2))
		return 0;

	ofstream of(fileName.c_str());

	for(int row = 0; row < rows1; row++){
		for(int col = 0; col < cols1; col++){
			int pixel1 = m1.at<uchar>(row,col);
			int pixel2 = m2.at<uchar>(row,col);
			int value = pixel1 - pixel2;
			of << value << ",";
 		}
		of << endl;
	}

	of.close();

}

int valueCheckAbs(Mat m1, Mat m2, String fileName){

	int rows1 = m1.rows;
	int cols1 = m1.cols;

	int rows2 = m2.rows;
	int cols2 = m2.cols;

	if ((rows1 != rows2) || (cols1 != cols2))
		return 0;

	ofstream of(fileName.c_str());

	for(int row = 0; row < rows1; row++){
		for(int col = 0; col < cols1; col++){
			int pixel1 = m1.at<uchar>(row,col);
			int pixel2 = m2.at<uchar>(row,col);
			int value = pixel1 - pixel2;
			of << abs(value) << ",";
 		}
		of << endl;
	}

	of.close();

}

int matValues(Mat m1, String fileName){

	int rows1  = m1.rows;
	int cols1 = m1.cols;

	ofstream of(fileName.c_str());

	for(int row = 0; row < rows1; row++){
		for(int col = 0; col < cols1; col++){
			int val = m1.at<uchar>(row,col);
			of << val << ",";
		}
		of << endl;
	}

	of.close();
}

Mat getBackgroundGroundTruthGray1(String fileName){

	cv::VideoCapture capture(fileName);
	Mat frame;

	if(!capture.isOpened()){
		return frame;
	}

	int numFrames = capture.get(CV_CAP_PROP_FRAME_COUNT);

	//cout << numFrames << endl;

	vector<Mat> allFrames;

	// store the video to a vector of frames
	int frameIndex = 0;

	while(frameIndex < numFrames) {
		if(!capture.read(frame))
			break;

			cvtColor(frame,frame, CV_BGR2GRAY);
			allFrames.push_back(frame);

			frameIndex++;
	}

	//cout << "test" << endl;
	//cout << allFrames.size() << endl;

	int rows = frame.rows;
	int cols = frame.cols;

	//int count = 0;
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
		//	cout << "COUNT " << count++ << " " << matrixElement << endl;
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

	int numFrames = capture.get(CV_CAP_PROP_FRAME_COUNT);

	vector<Mat> allFrames;

	// store the video to a vector of frames
	int frameIndex = 0;

	while(frameIndex < numFrames) {
		if(!capture.read(frame))
			break;

			cvtColor(frame,frame, CV_BGR2GRAY);
			allFrames.push_back(frame);

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

Mat getBackgroundGroundTruthGrayMean(String fileName){

	cv::VideoCapture capture(fileName);
		Mat frame;

		if(!capture.isOpened()){
			return frame;
		}

		int numFrames = capture.get(CV_CAP_PROP_FRAME_COUNT);

//		cout << numFrames << endl;

		vector<Mat> allFrames;

		// store the video to a vector of frames
		int frameIndex = 0;

		while(frameIndex < numFrames) {
			if(!capture.read(frame))
				break;

				cvtColor(frame,frame, CV_BGR2GRAY);
				allFrames.push_back(frame);

				frameIndex++;
		}

		//cout << "test" << endl;
		//cout << allFrames.size() << endl;

		int rows = frame.rows;
		int cols = frame.cols;
		int totalPixelVal = 0;
		int meanPixelVal = 0;
		//int count = 0;
		Mat displayFrame = allFrames.at(0);
		for(int row = 0; row < rows; row++){
			for(int col = 0; col < cols; col++){
				vector<int> histogramFrame;
				histogramFrame.resize(256);

				// add the total pixel value accross all frames
				for(int i = 0; i < numFrames; i++){
					int value = allFrames.at(i).at<uchar>(row,col);
					totalPixelVal = totalPixelVal + value;
				}

				//round-down value
				meanPixelVal = totalPixelVal/numFrames;

				displayFrame.at<uchar>(row,col) = meanPixelVal;
			//	cout << "COUNT " << count++ << " " << matrixElement << endl;
				totalPixelVal = 0;
				meanPixelVal = 0;
			}
		}
		capture.release();
		return displayFrame;
}

Mat getBackgroundGroundTruthGrayMedian(String fileName){
	cv::VideoCapture capture(fileName);
		Mat frame;

		if(!capture.isOpened()){
			return frame;
		}

		int numFrames = capture.get(CV_CAP_PROP_FRAME_COUNT);

//		cout << numFrames << endl;

		vector<Mat> allFrames;

		// store the video to a vector of frames
		int frameIndex = 0;

		while(frameIndex < numFrames) {
			if(!capture.read(frame))
				break;

				cvtColor(frame,frame, CV_BGR2GRAY);
				allFrames.push_back(frame);

				frameIndex++;
		}

		//cout << "test" << endl;
		//cout << allFrames.size() << endl;

		int rows = frame.rows;
		int cols = frame.cols;

		//int count = 0;
		Mat displayFrame = allFrames.at(0);
		for(int row = 0; row < rows; row++){
			for(int col = 0; col < cols; col++){
				vector<int> pixelValues;
				int num = 0;
				int ave = 0;

				// get the frequency of a color occurring at pixel position (r,c)
				for(int i = 0; i < numFrames; i++){
					int value = allFrames.at(i).at<uchar>(row,col);
					pixelValues.push_back(value);
				}

				// store the modal value at position (r,c) to the output matrix
				sort(pixelValues.rbegin(),pixelValues.rend());

				if(pixelValues.size()%2==0){
					num = pixelValues.size()/2;
					ave = (pixelValues.at(num-1) + pixelValues.at(num))/2;
					displayFrame.at<uchar>(row,col) = ave;
				}
				else{
					num = (pixelValues.size()/2);
					displayFrame.at<uchar>(row,col) = num;
				}

			//	cout << "COUNT " << count++ << " " << matrixElement << endl;
				pixelValues.clear();
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

	int numFrames = capture.get(CV_CAP_PROP_FRAME_COUNT);

	vector<Mat> allFrames;

	// store the video to a vector of frames
	int frameIndex = 0;

	while(frameIndex < numFrames) {
		if(!capture.read(frame))
		break;
		Mat frame2;
		frame.copyTo(frame2);

		allFrames.push_back(frame2);

		frameIndex++;
	}

	int rows = frame.rows;
	int cols = frame.cols;

	Mat displayFrame = allFrames.at(100);

	Mat testFrame;

	displayFrame.copyTo(testFrame);

	for(int row = 0; row < rows; row++){
		for(int col = 0; col < cols; col++){

			vector<int> histogramFrameBlue;
			histogramFrameBlue.resize(256);
			vector<int> histogramFrameGreen;
			histogramFrameGreen.resize(256);
			vector<int> histogramFrameRed;
			histogramFrameRed.resize(256);

			// get the frequency of a color occurring at pixel position (r,c) for every blue, green, red channels
			for(int i = 0; i < numFrames; i++){
				vector<Mat> matBands;
				split(allFrames.at(i), matBands);

				Mat coloredFrame = allFrames.at(i);
				int blueValue = coloredFrame.at<Vec3b>(row,col)[0];
				int greenValue = coloredFrame.at<Vec3b>(row,col)[1];
				int redValue = coloredFrame.at<Vec3b>(row,col)[2];

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

Mat getBackgroundGroundTruth2Colored(String fileName){

	cv::VideoCapture capture(fileName);
	Mat frame;

	if(!capture.isOpened()){
		return frame;
	}

	int numFrames = capture.get(CV_CAP_PROP_FRAME_COUNT);

	vector<Mat> allFrames;

	// store the video to a vector of frames
	int frameIndex = 0;

	while(frameIndex < numFrames) {
		if(!capture.read(frame))
			break;
			Mat frame2;
			frame.copyTo(frame2);

			allFrames.push_back(frame2);

			frameIndex++;
	}

	int rows = frame.rows;
	int cols = frame.cols;

	Mat displayFrame = allFrames.at(0);
	Mat testFrame;

	displayFrame.copyTo(testFrame);

	for(int row = 0; row < rows; row++){
		for(int col = 0; col < cols; col++){

			testFrame.at<Vec3b>(row,col)[0] = 0;
			testFrame.at<Vec3b>(row,col)[1] = 0;
			testFrame.at<Vec3b>(row,col)[2] = 0;

			// get the frequency of a color occurring at bit position "bit" from pixel position (r,c) for every blue, green, red channels
			int bitCheckerBlue = 1;
			int bitCheckerGreen = 1;
			int bitCheckerRed = 1;

			for(int bit = 0; bit < 8; bit++){
				int cntBitOneBlue = 0;
				int cntBitOneGreen = 0;
				int cntBitOneRed = 0;
				for (int i = 0; i < numFrames; ++i)
				{
					Mat coloredFrame = allFrames.at(i);
					int blueValue = coloredFrame.at<Vec3b>(row,col)[0];
					int greenValue = coloredFrame.at<Vec3b>(row,col)[1];
					int redValue = coloredFrame.at<Vec3b>(row,col)[2];

					if (blueValue & bitCheckerBlue)
						++cntBitOneBlue;
					else
						--cntBitOneBlue;
					if (greenValue & bitCheckerGreen)
						++cntBitOneGreen;
					else
						--cntBitOneGreen;
					if (redValue & bitCheckerRed)
						++cntBitOneRed;
					else
						--cntBitOneRed;
				}
				if (cntBitOneBlue > 0)
					testFrame.at<Vec3b>(row,col)[0] = bitCheckerBlue;
				if (cntBitOneGreen > 0)
					testFrame.at<Vec3b>(row,col)[1] = bitCheckerGreen;
				if (cntBitOneRed > 0)
					testFrame.at<Vec3b>(row,col)[2] = bitCheckerRed;


				bitCheckerBlue = bitCheckerBlue << 1;
				bitCheckerGreen = bitCheckerGreen << 1;
				bitCheckerRed = bitCheckerRed << 1;
			}
		}
	}

	capture.release();
	return testFrame;
}
Mat getBackgroundGroundTruthGrayRandom(String fileName, int numSamples){

	cv::VideoCapture capture(fileName);
	Mat frame;
	vector<Mat> imageRandom;

	if(!capture.isOpened()){
		return frame;
	}

	int numFrames = capture.get(CV_CAP_PROP_FRAME_COUNT);

	vector<Mat> allFrames;

	vector<int> newFrames = getRandomNumbers(numSamples,numFrames);

	// store the video to a vector of frames
	int frameIndex = 0;

	while(frameIndex < numFrames) {
		if(!capture.read(frame))
			break;

		cvtColor(frame,frame, CV_BGR2GRAY);
		allFrames.push_back(frame);

		frameIndex++;
	}

	int rows = frame.rows;
	int cols = frame.cols;

	cout << "size of eighty-one frames is: " << newFrames.size() << endl;
	cout << "all frames size: " << allFrames.size() << endl;

	//test
	//checker

	for(int i = 0; i < (int) newFrames.size(); i++){
		int number = newFrames.at(i);
		Mat imageCap = allFrames.at(number);
		imageRandom.push_back(imageCap);
	}

	cout << "size of image random is: " << imageRandom.size() << endl;

	Mat displayFrame = allFrames.at(0);
	for(int row = 0; row < rows; row++){
		for(int col = 0; col < cols; col++){
			displayFrame.at<uchar>(row,col) = 0;

			// get the frequency of a color occurring at bit position "bit" from pixel position (r,c)
			int bitChecker = 1;
			for(int bit = 0; bit < 8; bit++){
				int cntBitOne = 0;

				for (int i = 0; i < (int) imageRandom.size(); ++i)
				{
					int value = imageRandom.at(i).at<uchar>(row,col);
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


//start - new codes for the request

vector<Mat> fileNameGetBackground(String fileName){

	cv::VideoCapture capture(fileName);
	Mat frame;
	//vector<Mat> allFrames;

	if(!capture.isOpened()){
			return frame;
	}

	int numFrames = capture.get(CV_CAP_PROP_FRAME_COUNT);

	// store the video to a vector of frames
	int frameIndex = 0;

	while(frameIndex < numFrames) {
		if(!capture.read(frame))
			break;

		cvtColor(frame,frame, CV_BGR2GRAY);
		allFrames.push_back(frame);

		frameIndex++;
	}

	capture.release();

	return allFrames;

}


Mat getBackground(int numSamples, int levels){

	//vector<Mat> tournamentFrames;
	if(levels == 1)
	{
		vector<int> randomFrames;
		int numFrames = allFrames.size();

		for(int i = 0; i < numSamples; i++){
			int number = rand() % numFrames;
			Mat imageCap = allFrames.at(number);
			cout << i << " - " << number << endl;
			//char buffTitle[256];
			//sprintf(buffTitle, "%i", number);
			//imshow(buffTitle, imageCap);
			tournamentFrames.push_back(imageCap);
		}
	}
	else{
		for(int i = 0; i < numSamples; i++){
			//something's wrong
//			tournamentFrames.clear();
			Mat frame = getBackground(numSamples, levels - 1);

			cout << i << endl;
			//string levelNumber = i;
			string title = "TITLE";
	//		imshow(title,frame);
			tournamentFrames.push_back(frame);

		//	frame.deallocate();
		/**	int rows = tournamentFrames.at(0).rows;
			int cols = tournamentFrames.at(0).cols;
			for(int row = 0; row < rows; row++){
					cout << "start ";
					for(int col = 0; col < cols; col++){
						int value = tournamentFrames.at(i).at<uchar>(row,col);
						cout << value << " ";
					}
					cout << endl;
			}**/
		}
	}

	Mat result = getBackgroundImage(tournamentFrames, numSamples);

	//imshow("Result", result);
	//imshow("Result", result);
	//cout << "TESTING PLS" << endl;
	return result;
}


Mat getBackgroundImage(vector<Mat> tournamentFrames, int numSamples){

//	vector<Mat> imageRandom;

//	cout << "size of image random is: " << imageRandom.size() << endl;

	int numFrames = tournamentFrames.size();
	cout << numFrames << endl;
	//for (int i = 0; i < numFrames; ++i)
	//{
	//	char buffTitle[256];
	//	sprintf(buffTitle, "%i", i);
	//	imshow(buffTitle, tournamentFrames.at(i));
	//}


	Mat displayFrameRef = allFrames.at(0);
	int rows = displayFrameRef.rows;
	int cols = displayFrameRef.cols;

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
					int value = tournamentFrames.at(i).at<uchar>(row,col);
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
	//cout << "TEST" << endl;
	//imshow("test", displayFrame);

	//imshow("disp", displayFrame);
	//cout << "TEST" << endl;
	//tournamentFrames.clear();
	return displayFrame;
}

//end - new codes for the request

Mat getBackgroundGroundTruthGrayRandom2Levels(String fileName){

	Mat truthRandom1;
	Mat truthRandom2;
	Mat truthRandom3;
	Mat truthRandom4;
	Mat truthRandom5;
	Mat truthRandom6;
	Mat truthRandom7;
	Mat truthRandom8;
	Mat truthRandom9;

	cv::VideoCapture capture(fileName);
	Mat frame;
	vector<Mat> imageRandom;

	if(!capture.isOpened()){
		return frame;
	}

	int numFrames = capture.get(CV_CAP_PROP_FRAME_COUNT);

	vector<Mat> allFrames;

	// store the video to a vector of frames
	int frameIndex = 0;

	while(frameIndex < numFrames) {
		if(!capture.read(frame))
			break;

		cvtColor(frame,frame, CV_BGR2GRAY);
		allFrames.push_back(frame);

		frameIndex++;
	}

	int rows = frame.rows;
	int cols = frame.cols;

	truthRandom1 = getBackgroundGroundTruthGrayRandom(fileName, 9);
	truthRandom2 = getBackgroundGroundTruthGrayRandom(fileName, 9);
	truthRandom3 = getBackgroundGroundTruthGrayRandom(fileName, 9);
	truthRandom4 = getBackgroundGroundTruthGrayRandom(fileName, 9);
	truthRandom5 = getBackgroundGroundTruthGrayRandom(fileName, 9);
	truthRandom6 = getBackgroundGroundTruthGrayRandom(fileName, 9);
	truthRandom7 = getBackgroundGroundTruthGrayRandom(fileName, 9);
	truthRandom8 = getBackgroundGroundTruthGrayRandom(fileName, 9);
	truthRandom9 = getBackgroundGroundTruthGrayRandom(fileName, 9);

	imageRandom.push_back(truthRandom1);
	imageRandom.push_back(truthRandom2);
	imageRandom.push_back(truthRandom3);
	imageRandom.push_back(truthRandom4);
	imageRandom.push_back(truthRandom5);
	imageRandom.push_back(truthRandom6);
	imageRandom.push_back(truthRandom7);
	imageRandom.push_back(truthRandom8);
	imageRandom.push_back(truthRandom9);

	Mat displayFrame = allFrames.at(0);
	for(int row = 0; row < rows; row++){
		for(int col = 0; col < cols; col++){
			displayFrame.at<uchar>(row,col) = 0;

			// get the frequency of a color occurring at bit position "bit" from pixel position (r,c)
			int bitChecker = 1;
			for(int bit = 0; bit < 8; bit++){
				int cntBitOne = 0;

				for (int i = 0; i < (int) imageRandom.size(); ++i)
				{
					int value = imageRandom.at(i).at<uchar>(row,col);
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

//Patricia
Mat TF_L4_Image ( String sourceReference ){

	VideoCapture capvid(sourceReference);
		Mat error;
		if ( !capvid.isOpened()) {
			cout << "Could not open reference " << sourceReference << endl;
			return error; }

		int count = capvid.get(CV_CAP_PROP_FRAME_COUNT);
	//	double rate = capvid.get(CV_CAP_PROP_FPS);
		//int delay = 100/rate;

		Mat origvid, origvidpass, copypass;
		vector<Mat> origvideo;
		origvideo.resize(count);
		int frameIndex = 0;
		for (frameIndex = 0; frameIndex < count; frameIndex++) {
			if( !capvid.read(origvid)) break;
			capvid >> origvidpass;
			origvidpass.copyTo(copypass);
			origvideo.at(frameIndex).push_back(copypass);
			origvideo.resize(count);
	//		imshow("read", origvid);

		}
		cout << "\nframeIndex: " << frameIndex;
		origvideo.resize(frameIndex);
		cout << "\nTotal vector<Mat>origvideo elements: " << origvideo.size();

		//changed to 4
		int levels = 4;
		int frames = pow(3.0,levels);
		cout << "\nFrames: " << frames;
		vector<Mat> startframes;
		startframes.resize(frames);
		int framepos = 0;
		RNG rng(1);
		Mat rndframe, copyrndframe;
		for ( int i = 0; i < frames; i++) {
			framepos = rng.uniform(0, origvideo.size());
			capvid.set(CV_CAP_PROP_POS_FRAMES, framepos);
			capvid >> rndframe;
			cvtColor(rndframe, rndframe, CV_BGR2GRAY);
			rndframe.copyTo(copyrndframe);
			startframes.at(i).push_back(copyrndframe);
			startframes.resize(frames);
		}
		cout << "\nTotal vector<Mat>startframes elements: " << startframes.size();
		vector<Mat> currLevel = startframes;
		cout << "\nTotal vector<Mat>currLevel elements: " << currLevel.size();


		vector<Mat> nextLevel;
		int push = 0;
		int i = 0;
		//place time here
		clock_t t1, t2;
		t1 = clock();
		//double t1 = time(0);
		while (( i < levels) && (frames > 1)) {
			cout << "\nLevel: " << i << endl;
			for (int j = 0; j < frames; j+=3) {
	//			cout << "\nj: " << j;
				vector<Mat> videovecmat;
				videovecmat.resize(3);
				Mat frame1 = currLevel.at(j);
				Mat frame2 = currLevel.at(j+1);
				Mat frame3 = currLevel.at(j+2);
				videovecmat.at(0) = frame1;
				videovecmat.at(1) = frame2;
				videovecmat.at(2) = frame3;
				Mat booleanBG = getBG (frame1, frame2, frame3);
				nextLevel.push_back(booleanBG);
			}

			currLevel.resize(nextLevel.size());
			currLevel = nextLevel;

			i++;
			frames = frames/3;
			push = push + frames;
		}
		//double t2 = time(0);
		//double time = t2-t1;
		t2 = clock();
		float time = ((float) t2- (float) t1) / 1000000.0F;
		cout << time << " seconds."<< endl;

	Mat Level4_TF_GS = nextLevel.at(push-1);

return Level4_TF_GS;
}


vector<int> getRandomNumbersUnique(int output, int totalFrames){

	vector<int> randomFrames;
	vector<int> tempFrames;
	tempFrames.resize(totalFrames+1);

	srand ( time(NULL) );

	for(int i = 0; i < output; i++){
		int randomNumber =  rand() % totalFrames;
	//	cout << "FROM THE METHOD: " << randomNumber << endl;
		if(tempFrames.at(randomNumber)==0){
			tempFrames.at(randomNumber)=1;
		}
		else{
			i--;
		}
	}
	for(int i = 0; i < totalFrames + 1; i++){
		if(tempFrames.at(i)==1){
			randomFrames.push_back(i);
		}
	}

	return randomFrames;
}

vector<int> getRandomNumbers(int output, int totalFrames){
	vector<int> randomFrames;

	srand ( time(NULL) );

	for (int i = 0; i < output; i++){
		int randomNumber = rand() % totalFrames;
		randomFrames.push_back(randomNumber);
	}

	return randomFrames;
}
Mat getBG (Mat frame1, Mat frame2, Mat frame3) {
	Mat oneandtwo, oneandthree, twoandthree, onetwothree;
		bitwise_and(frame1, frame2, oneandtwo);
		bitwise_and(frame1, frame3, oneandthree);
		bitwise_and(frame2, frame3, twoandthree);
		bitwise_and(oneandtwo, frame3, onetwothree);
	Mat notone, nottwo, notthree;
		bitwise_not(frame1, notone);
		bitwise_not(frame2, nottwo);
		bitwise_not(frame3, notthree);
	Mat notoneandtwothree, nottwoandonethree, notthreeandonetwo;
		bitwise_and(notone, twoandthree, notoneandtwothree);
		bitwise_and(nottwo, oneandthree, nottwoandonethree);
		bitwise_and(notthree, oneandtwo, notthreeandonetwo);
	Mat termab, termabc, termabcd;
		bitwise_or(notoneandtwothree, nottwoandonethree, termab);
		bitwise_or(termab, notthreeandonetwo, termabc);
		bitwise_or(termabc, onetwothree, termabcd);
	return termabcd;
}

Mat getBackgroundGroundTruthColoredRandom(String fileName, int number){

	cv::VideoCapture capture(fileName);
	Mat frame;
	vector<Mat> imageRandom;

		if(!capture.isOpened()){
			return frame;
		}

		int numFrames = capture.get(CV_CAP_PROP_FRAME_COUNT);

		vector<Mat> allFrames;

		vector<int> newFrames = getRandomNumbers(number,numFrames);

		// store the video to a vector of frames
		int frameIndex = 0;

		while(frameIndex < numFrames) {
			if(!capture.read(frame))
				break;
				Mat frame2;
				frame.copyTo(frame2);

				allFrames.push_back(frame2);

				frameIndex++;
		}

		int rows = frame.rows;
		int cols = frame.cols;

		for(int i = 0; i < (int) newFrames.size(); i++){
			int number = newFrames.at(i);
			Mat imageCap = allFrames.at(number);
			imageRandom.push_back(imageCap);
		}

		Mat displayFrame = allFrames.at(0);
		Mat testFrame;

		displayFrame.copyTo(testFrame);

		for(int row = 0; row < rows; row++){
			for(int col = 0; col < cols; col++){

				testFrame.at<Vec3b>(row,col)[0] = 0;
				testFrame.at<Vec3b>(row,col)[1] = 0;
				testFrame.at<Vec3b>(row,col)[2] = 0;

				// get the frequency of a color occurring at bit position "bit" from pixel position (r,c) for every blue, green, red channels
				int bitCheckerBlue = 1;
				int bitCheckerGreen = 1;
				int bitCheckerRed = 1;

				for(int bit = 0; bit < 8; bit++){
					int cntBitOneBlue = 0;
					int cntBitOneGreen = 0;
					int cntBitOneRed = 0;
					for (int i = 0; i < (int) imageRandom.size(); ++i)
					{
						Mat coloredFrame = imageRandom.at(i);
						int blueValue = coloredFrame.at<Vec3b>(row,col)[0];
						int greenValue = coloredFrame.at<Vec3b>(row,col)[1];
						int redValue = coloredFrame.at<Vec3b>(row,col)[2];

						if (blueValue & bitCheckerBlue)
							++cntBitOneBlue;
						else
							--cntBitOneBlue;
						if (greenValue & bitCheckerGreen)
							++cntBitOneGreen;
						else
							--cntBitOneGreen;
						if (redValue & bitCheckerRed)
							++cntBitOneRed;
						else
							--cntBitOneRed;
					}
					if (cntBitOneBlue > 0)
						testFrame.at<Vec3b>(row,col)[0] = bitCheckerBlue;
					if (cntBitOneGreen > 0)
						testFrame.at<Vec3b>(row,col)[1] = bitCheckerGreen;
					if (cntBitOneRed > 0)
						testFrame.at<Vec3b>(row,col)[2] = bitCheckerRed;


					bitCheckerBlue = bitCheckerBlue << 1;
					bitCheckerGreen = bitCheckerGreen << 1;
					bitCheckerRed = bitCheckerRed << 1;
				}
			}
		}
		capture.release();
		return testFrame;
}

Mat getBackgroundGroundTruthColoredRandom2Levels(String fileName){

	Mat truthRandom1;
	Mat truthRandom2;
	Mat truthRandom3;
	Mat truthRandom4;
	Mat truthRandom5;
	Mat truthRandom6;
	Mat truthRandom7;
	Mat truthRandom8;
	Mat truthRandom9;

	cv::VideoCapture capture(fileName);
	Mat frame;
	vector<Mat> imageRandom;

	int rows = frame.rows;
	int cols = frame.cols;

	truthRandom1 = getBackgroundGroundTruthColoredRandom(fileName, 9);
	truthRandom2 = getBackgroundGroundTruthColoredRandom(fileName, 9);
	truthRandom3 = getBackgroundGroundTruthColoredRandom(fileName, 9);
	truthRandom4 = getBackgroundGroundTruthColoredRandom(fileName, 9);
	truthRandom5 = getBackgroundGroundTruthColoredRandom(fileName, 9);
	truthRandom6 = getBackgroundGroundTruthColoredRandom(fileName, 9);
	truthRandom7 = getBackgroundGroundTruthColoredRandom(fileName, 9);
	truthRandom8 = getBackgroundGroundTruthColoredRandom(fileName, 9);
	truthRandom9 = getBackgroundGroundTruthColoredRandom(fileName, 9);

	imageRandom.push_back(truthRandom1);
	imageRandom.push_back(truthRandom2);
	imageRandom.push_back(truthRandom3);
	imageRandom.push_back(truthRandom4);
	imageRandom.push_back(truthRandom5);
	imageRandom.push_back(truthRandom6);
	imageRandom.push_back(truthRandom7);
	imageRandom.push_back(truthRandom8);
	imageRandom.push_back(truthRandom9);

	Mat displayFrame = imageRandom.at(0);
	Mat testFrame;

	displayFrame.copyTo(testFrame);

	for(int row = 0; row < rows; row++){
		for(int col = 0; col < cols; col++){

			testFrame.at<Vec3b>(row,col)[0] = 0;
			testFrame.at<Vec3b>(row,col)[1] = 0;
			testFrame.at<Vec3b>(row,col)[2] = 0;

			// get the frequency of a color occurring at bit position "bit" from pixel position (r,c) for every blue, green, red channels
			int bitCheckerBlue = 1;
			int bitCheckerGreen = 1;
			int bitCheckerRed = 1;

			for(int bit = 0; bit < 8; bit++){
				int cntBitOneBlue = 0;
				int cntBitOneGreen = 0;
				int cntBitOneRed = 0;
					for (int i = 0; i < 9; ++i)
					{
						Mat coloredFrame = imageRandom.at(i);
						int blueValue = coloredFrame.at<Vec3b>(row,col)[0];
						int greenValue = coloredFrame.at<Vec3b>(row,col)[1];
						int redValue = coloredFrame.at<Vec3b>(row,col)[2];

						if (blueValue & bitCheckerBlue)
							++cntBitOneBlue;
						else
							--cntBitOneBlue;
						if (greenValue & bitCheckerGreen)
							++cntBitOneGreen;
						else
							--cntBitOneGreen;
						if (redValue & bitCheckerRed)
							++cntBitOneRed;
						else
							--cntBitOneRed;
					}
					if (cntBitOneBlue > 0)
						testFrame.at<Vec3b>(row,col)[0] = bitCheckerBlue;
					if (cntBitOneGreen > 0)
						testFrame.at<Vec3b>(row,col)[1] = bitCheckerGreen;
					if (cntBitOneRed > 0)
						testFrame.at<Vec3b>(row,col)[2] = bitCheckerRed;


					bitCheckerBlue = bitCheckerBlue << 1;
					bitCheckerGreen = bitCheckerGreen << 1;
					bitCheckerRed = bitCheckerRed << 1;
			}
		}
	}

	capture.release();
	return displayFrame;
}

