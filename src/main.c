/*
 * main.c
 * Sets up a Window and BitmapLayer, then loads and displays a PNG as a GBitmap
 */

#include <pebble.h>
#define ACCEL_RATIO 0.05
#define ACCEL_STEP_MS 50
  
static Window *window;
static GBitmap *seasick_the_cat_bmp_01;
static GBitmap *seasick_the_cat_bmp_02;
static GBitmap *seasick_the_cat_bmp_03;
static GBitmap *seasick_the_cat_bmp_04;
static GBitmap *seasick_the_cat_bmp_05;
static GBitmap *seasick_the_cat_bmp_06;
static GBitmap *seasick_the_cat_bmp_07;
static GBitmap *seasick_the_cat_bmp_08;
static GBitmap *seasick_the_cat_bmp_09;
static GBitmap *seasick_the_cat_bmp_10;
static GBitmap *seasick_the_cat_bmp_11;
static GBitmap *seasick_the_cat_bmp_12;
static BitmapLayer *image_layer;
int animation_frame = 0;


//handler
static void data_handler(AccelData *data, uint32_t num_samples) {
  double y_val = data[0].z;
  
  if(y_val > 0 && animation_frame < 12){
    animation_frame++;
  }
  else if(y_val < 0 && animation_frame < 1)
  {
    animation_frame--;
  }
  
 
  
  switch (animation_frame){
    case 0:
    bitmap_layer_set_bitmap(image_layer, seasick_the_cat_bmp_01);
    break;
    case 1:
    bitmap_layer_set_bitmap(image_layer, seasick_the_cat_bmp_01);
    break;
    case 2:
    bitmap_layer_set_bitmap(image_layer, seasick_the_cat_bmp_02);
    break;
    case 3:
    bitmap_layer_set_bitmap(image_layer, seasick_the_cat_bmp_03);
    break;
    case 4:
    bitmap_layer_set_bitmap(image_layer, seasick_the_cat_bmp_04);
    break;
    case 5:
    bitmap_layer_set_bitmap(image_layer, seasick_the_cat_bmp_05);
    break;
    case 6:
    bitmap_layer_set_bitmap(image_layer, seasick_the_cat_bmp_06);
    break;
    case 7:
    bitmap_layer_set_bitmap(image_layer, seasick_the_cat_bmp_07);
    break;
    case 8:
    bitmap_layer_set_bitmap(image_layer, seasick_the_cat_bmp_08);
    break;
    case 9:
    bitmap_layer_set_bitmap(image_layer, seasick_the_cat_bmp_09);
    break;
    case 10:
    bitmap_layer_set_bitmap(image_layer, seasick_the_cat_bmp_10);
    break;
    case 11:
    bitmap_layer_set_bitmap(image_layer, seasick_the_cat_bmp_11);
    break;
    case 12:
    bitmap_layer_set_bitmap(image_layer, seasick_the_cat_bmp_12);
    break;
    case 13:
    bitmap_layer_set_bitmap(image_layer, seasick_the_cat_bmp_12);
    break;
  }
  
  
  

  
    

}
// By calling window_single_click_subscribe , you "wiring up" the appropriate button to the correct event handler above.
// and telling the pebble to "listen" for that button press



static void main_window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  //load up frames of animation
  seasick_the_cat_bmp_01 = gbitmap_create_with_resource(RESOURCE_ID_BARF_01_BLACK);
  seasick_the_cat_bmp_02 = gbitmap_create_with_resource(RESOURCE_ID_BARF_02_BLACK);
  seasick_the_cat_bmp_03 = gbitmap_create_with_resource(RESOURCE_ID_BARF_03_BLACK);
  seasick_the_cat_bmp_04 = gbitmap_create_with_resource(RESOURCE_ID_BARF_04_BLACK);
  seasick_the_cat_bmp_05 = gbitmap_create_with_resource(RESOURCE_ID_BARF_05_BLACK);
  seasick_the_cat_bmp_06 = gbitmap_create_with_resource(RESOURCE_ID_BARF_06_BLACK);
  seasick_the_cat_bmp_07 = gbitmap_create_with_resource(RESOURCE_ID_BARF_07_BLACK);
  seasick_the_cat_bmp_08 = gbitmap_create_with_resource(RESOURCE_ID_BARF_08_BLACK);
  seasick_the_cat_bmp_09 = gbitmap_create_with_resource(RESOURCE_ID_BARF_09_BLACK);
  seasick_the_cat_bmp_10 = gbitmap_create_with_resource(RESOURCE_ID_BARF_10_BLACK);
  seasick_the_cat_bmp_11 = gbitmap_create_with_resource(RESOURCE_ID_BARF_11_BLACK);
  seasick_the_cat_bmp_12 = gbitmap_create_with_resource(RESOURCE_ID_BARF_12_BLACK);
  
  
  
  
  image_layer = bitmap_layer_create(bounds);
  bitmap_layer_set_background_color(image_layer, GColorClear);
  bitmap_layer_set_bitmap(image_layer, seasick_the_cat_bmp_01);


  
  layer_add_child(window_layer, bitmap_layer_get_layer(image_layer));
}

static void main_window_unload(Window *window) {
  gbitmap_destroy(seasick_the_cat_bmp_01);
  gbitmap_destroy(seasick_the_cat_bmp_02);
  gbitmap_destroy(seasick_the_cat_bmp_03);
  gbitmap_destroy(seasick_the_cat_bmp_04);
  gbitmap_destroy(seasick_the_cat_bmp_05);
  gbitmap_destroy(seasick_the_cat_bmp_06);
  gbitmap_destroy(seasick_the_cat_bmp_07);
  gbitmap_destroy(seasick_the_cat_bmp_08);
  gbitmap_destroy(seasick_the_cat_bmp_09);
  gbitmap_destroy(seasick_the_cat_bmp_10);
  gbitmap_destroy(seasick_the_cat_bmp_11);
  gbitmap_destroy(seasick_the_cat_bmp_12);
  bitmap_layer_destroy(image_layer);
  
}

static void init() {
  window = window_create();
  window_set_background_color(window, GColorBlack);
  window_set_window_handlers(window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload,
  });
  window_stack_push(window, true);
  
   // Subscribe to the accelerometer data service
    int num_samples = 3;
    accel_data_service_subscribe(num_samples, data_handler);

    // Choose update rate
    accel_service_set_sampling_rate(ACCEL_SAMPLING_10HZ);
    accel_service_set_samples_per_update(25)
  
   
}

static void deinit() {
  accel_data_service_unsubscribe();
  window_destroy(window);
  
}

int main() {
  init();
  app_event_loop();
  deinit();
}