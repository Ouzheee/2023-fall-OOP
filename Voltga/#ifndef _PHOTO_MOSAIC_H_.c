#ifndef _PHOTO_MOSAIC_H_
#define _PHOTO_MOSAIC_H_      
#include "image.h"         
#include <string>  
  
class PhotoMosaic : public Image{    
  private: 
    int ***T_pixels,***S_pixels,**T_pixels_,**S_pixels_;  //
    string Dumpname; 
    vector<string> _list;
    vector<string> _list_rgb;
    int s_imgh,s_imgw; 
  public:
    PhotoMosaic();  
    PhotoMosaic(int w,int h,int ***pixels);  
    ~PhotoMosaic();  
    bool LoadImage_List(string directoryPath);
    bool LoadImage_Target(string filename);  
    bool LoadImage_Target_gray(string filename);//
    bool PhotoMosaic_Start(); 
    bool PhotoMosaic_Start_gray();//
    bool LoadImage_Source(string filename);//0526
    bool PhotoMosaic_1pic_Start(string filename,int n);//0526
    bool PhotoMosaic_1pic_Start_RGB(string filename,int n);
    void DumpImage(string filename);
    void DumpImage_gray(string filename);
    void Display_X_Server();
    void Display_ASCII();
    void Display_CMD(); 
    
    friend int find_diff(int,int,PhotoMosaic&,int[][3]);
    friend int find_diff_gray(int,int,PhotoMosaic&,int[]);//
    
       
};

#endif