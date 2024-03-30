// Project1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
int main() {
   setlocale(LC_ALL, "Russian");

   cv::Mat image1 = cv::Mat::zeros(500, 500, CV_8UC3);
   int width = image1.cols;
   int height = image1.rows;
   cv::putText(image1, std::to_string(width), cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 255, 255), 2);
   cv::putText(image1, "x", cv::Point(70, 30), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 255, 255), 2);
   cv::putText(image1, std::to_string(height), cv::Point(90, 30), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 255, 255), 2);

   //треугольник
   cv::Point pt1(250, 100);
   cv::Point pt2(100, 400);
   cv::Point pt3(400, 400);
   fillConvexPoly(image1, std::vector<cv::Point>{pt1, pt2, pt3}, cv::Scalar(255, 0, 0));
   //треугольник
   cv::Point pt4(200, 200);
   cv::Point pt5(50, 450);
   cv::Point pt6(350, 450);
   line(image1, pt4, pt5, cv::Scalar(0, 255, 0), 2);
   line(image1, pt5, pt6, cv::Scalar(0, 255, 0), 3);
   line(image1, pt6, pt4, cv::Scalar(0, 255, 0), 3);
   
   cv::rectangle(image1, cv::Point(50, 50), cv::Point(200, 200), CV_RGB(255, 0, 0), -1);
   cv::circle(image1, cv::Point(300, 100), 50, CV_RGB(0, 255, 0), -1);

   cv::rectangle(image1, cv::Point(250, 250), cv::Point(400, 400), CV_RGB(0, 0, 155), 2);
   cv::circle(image1, cv::Point(100, 400), 50, CV_RGB(255, 255, 0), 2);

   cv::ellipse(image1, cv::Point(400, 400), cv::Size(60, 40), 45, 0, 360, cv::Scalar(0, 0, 255), -1);
  

   cv::Mat image = cv::imread("D:/virandfpc/channels4_profile.jpg");

   if (image.empty()) {
      std::cout << "Ошибка загрузки изображения" << std::endl;
      return -1;
   }

   int width1 = image.cols;
   int height1 = image.rows;

   cv::Rect roi1(0, 0, image.cols / 2, image.rows / 2);
   cv::Rect roi2(image.cols / 2, 0, image.cols / 2, image.rows / 2);
   cv::Rect roi3(0, image.rows / 2, image.cols / 2, image.rows / 2);
   cv::Rect roi4(image.cols / 2, image.rows / 2, image.cols / 2, image.rows / 2);

   cv::Mat part1 = image(roi1);
   cv::Mat part2 = image(roi2);
   cv::Mat part3 = image(roi3);
   cv::Mat part4 = image(roi4);

   int radius = std::min(width1, height1) / 3;
   cv::Mat mask = cv::Mat::zeros(image.size(), CV_8UC1);
   std::vector<cv::Point> pts;
   for (int i = 0; i < 6; i++) {
      double angle = 2 * CV_PI / 6 * i;
      int vertexX = width1 / 2 + radius * cos(angle);
      int vertexY = height1 / 2 + radius * sin(angle);
      pts.push_back(cv::Point(vertexX, vertexY));
   };
   cv::fillConvexPoly(mask, pts, cv::Scalar(255));


   cv::Mat result;
   image.copyTo(result, mask);


   cv::imshow("Hexagon_Result", result);


   imshow("1", part1);
   imshow("2", part2);
   imshow("3", part3);
   imshow("4", part4);
   cv::imshow("Image", image1);
   cv::waitKey(0);

   return 0;

   return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
