#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#if defined(LV_LVGL_H_INCLUDE_SIMPLE)
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_PROCESSOR
#define LV_ATTRIBUTE_IMG_PROCESSOR
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_PROCESSOR uint8_t processor_map[] = {
    0x3c, 0x73, 0x76, 0x67, 0x20, 0x78, 0x6d, 0x6c, 0x6e, 0x73, 0x3d, 0x22, 0x68, 
    0x74, 0x74, 0x70, 0x3a, 0x2f, 0x2f, 0x77, 0x77, 0x77, 0x2e, 0x77, 0x33, 0x2e, 
    0x6f, 0x72, 0x67, 0x2f, 0x32, 0x30, 0x30, 0x30, 0x2f, 0x73, 0x76, 0x67, 0x22, 
    0x20, 0x66, 0x69, 0x6c, 0x6c, 0x3d, 0x22, 0x6e, 0x6f, 0x6e, 0x65, 0x22, 0x20, 
    0x73, 0x74, 0x72, 0x6f, 0x6b, 0x65, 0x3d, 0x22, 0x63, 0x75, 0x72, 0x72, 0x65, 
    0x6e, 0x74, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x22, 0x20, 0x73, 0x74, 0x72, 0x6f, 
    0x6b, 0x65, 0x2d, 0x6c, 0x69, 0x6e, 0x65, 0x63, 0x61, 0x70, 0x3d, 0x22, 0x72, 
    0x6f, 0x75, 0x6e, 0x64, 0x22, 0x20, 0x73, 0x74, 0x72, 0x6f, 0x6b, 0x65, 0x2d, 
    0x6c, 0x69, 0x6e, 0x65, 0x6a, 0x6f, 0x69, 0x6e, 0x3d, 0x22, 0x72, 0x6f, 0x75, 
    0x6e, 0x64, 0x22, 0x20, 0x73, 0x74, 0x72, 0x6f, 0x6b, 0x65, 0x2d, 0x77, 0x69, 
    0x64, 0x74, 0x68, 0x3d, 0x22, 0x31, 0x22, 0x20, 0x76, 0x69, 0x65, 0x77, 0x42, 
    0x6f, 0x78, 0x3d, 0x22, 0x30, 0x20, 0x30, 0x20, 0x32, 0x34, 0x20, 0x32, 0x34, 
    0x22, 0x3e, 0x3c, 0x70, 0x61, 0x74, 0x68, 0x20, 0x64, 0x3d, 0x22, 0x4d, 0x36, 
    0x20, 0x38, 0x61, 0x32, 0x20, 0x32, 0x20, 0x30, 0x20, 0x30, 0x20, 0x31, 0x20, 
    0x32, 0x2d, 0x32, 0x68, 0x38, 0x61, 0x32, 0x20, 0x32, 0x20, 0x30, 0x20, 0x30, 
    0x20, 0x31, 0x20, 0x32, 0x20, 0x32, 0x76, 0x38, 0x61, 0x32, 0x20, 0x32, 0x20, 
    0x30, 0x20, 0x30, 0x20, 0x31, 0x2d, 0x32, 0x20, 0x32, 0x48, 0x38, 0x61, 0x32, 
    0x20, 0x32, 0x20, 0x30, 0x20, 0x30, 0x20, 0x31, 0x2d, 0x32, 0x2d, 0x32, 0x56, 
    0x38, 0x7a, 0x4d, 0x32, 0x30, 0x20, 0x31, 0x32, 0x68, 0x2d, 0x32, 0x6d, 0x32, 
    0x2d, 0x34, 0x68, 0x2d, 0x32, 0x6d, 0x32, 0x20, 0x38, 0x68, 0x2d, 0x32, 0x4d, 
    0x36, 0x20, 0x31, 0x32, 0x48, 0x34, 0x6d, 0x32, 0x20, 0x34, 0x48, 0x34, 0x6d, 
    0x32, 0x2d, 0x38, 0x48, 0x34, 0x6d, 0x38, 0x2d, 0x34, 0x76, 0x32, 0x4d, 0x38, 
    0x20, 0x34, 0x76, 0x32, 0x6d, 0x38, 0x2d, 0x32, 0x76, 0x32, 0x6d, 0x2d, 0x34, 
    0x20, 0x31, 0x32, 0x76, 0x32, 0x6d, 0x2d, 0x34, 0x2d, 0x32, 0x76, 0x32, 0x6d, 
    0x38, 0x2d, 0x32, 0x76, 0x32, 0x22, 0x3e, 0x3c, 0x2f, 0x70, 0x61, 0x74, 0x68, 
    0x3e, 0x3c, 0x2f, 0x73, 0x76, 0x67, 0x3e
};

const lv_img_dsc_t processor = {
  .header.cf = LV_IMG_CF_RAW_CHROMA_KEYED,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 0,
  .header.h = 0,
  .data_size = 332,
  .data = processor_map,
};
