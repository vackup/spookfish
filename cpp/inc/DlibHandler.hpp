#ifndef DLIB_HANDLER_HPP
#define DLIB_HANDLER_HPP

#include <vector>

#include <dlib/string.h>
#include <dlib/dnn.h>
#include <dlib/image_io.h>
#include <dlib/opencv.h>
#include <dlib/image_processing.h>
#include <dlib/image_processing/frontal_face_detector.h>

#include "NotCopyable.hpp"
#include "RsNetDlib.hpp"
#include "DrawingUtils.hpp"

class DlibHandler : public NotCopyable
{
  private:
    cv::Mat RgbImage;
    cv::Mat BgrImage;
    uint16_t TotalFacesInImage;
    DrawingUtils Shape;
    dlib::frontal_face_detector FaceDetector;
    dlib::shape_predictor LandMarkDetector;
    anet_type AnetType;
    dlib::matrix<dlib::rgb_pixel> DlibImageMat;
    std::vector<dlib::rectangle> FaceRectangles;
    std::vector<dlib::full_object_detection>  LandMarks;
    std::vector<dlib::matrix<rgb_pixel>> FaceChips;
    std::vector<dlib::matrix<float,0,1>> FaceDescriptionQuerys;

    DlibHandler() = delete;
    void ProcessImage();
    void FaceDetection();
    void LandmarkDetector();
    void DrawShapes(cv::Mat &);
  public:
    explicit DlibHandler(std::string &shapePredictFile, std::string &faceRecRsNetFile);
    ~DlibHandler();
    void ProcessData(cv::Mat &);
};

#endif // DLIB_HANDLER_HPP
