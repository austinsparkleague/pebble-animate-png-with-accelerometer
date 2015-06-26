/*
 * main.c
 * Sets up a Window and BitmapLayer, then loads and displays a PNG as a GBitmap
 */

#include <pebble.h>

static Window *window;
static GBitmap *seasick_the_cat_bmp_1;
static GBitmap *seasick_the_cat_bmp_2;
static GBitmap *seasick_the_cat_bmp_3;
static GBitmap *seasick_the_cat_bmp_4;
static BitmapLayer *image_layer;

// All of the handlers, this is where you define the actual steps that take place 
// after the button press has been detected


static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
//  text_layer_set_text(text_layer, "Up");
  bitmap_layer_set_bitmap(image_layer, seasick_the_cat_bmp_2);
}

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
//  text_layer_set_text(text_layer, "Select");
  bitmap_layer_set_bitmap(image_layer, seasick_the_cat_bmp_3);
}

static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
//  text_layer_set_text(text_layer, "Down");
  bitmap_layer_set_bitmap(image_layer, seasick_the_cat_bmp_4);
}


// By calling window_single_click_subscribe , you "wiring up" the appropriate button to the correct event handler above.
// and telling the pebble to "listen" for that button press
static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
}


static void main_window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  //load up frames of animation
  seasick_the_cat_bmp_1 = gbitmap_create_with_resource(RESOURCE_ID_BARF_01_BLACK);
  seasick_the_cat_bmp_2 = gbitmap_create_with_resource(RESOURCE_ID_BARF_04_BLACK);
  seasick_the_cat_bmp_3 = gbitmap_create_with_resource(RESOURCE_ID_BARF_08_BLACK);
  seasick_the_cat_bmp_4 = gbitmap_create_with_resource(RESOURCE_ID_BARF_12_BLACK);
  

  
  
  image_layer = bitmap_layer_create(bounds);
  bitmap_layer_set_background_color(image_layer, GColorClear);
  bitmap_layer_set_bitmap(image_layer, seasick_the_cat_bmp_1);
  //bitmap_layer_set_compositing_mode(image_layer, GCompOpAssign);

  layer_add_child(window_layer, bitmap_layer_get_layer(image_layer));
}

static void main_window_unload(Window *window) {
  gbitmap_destroy(seasick_the_cat_bmp_1);
  gbitmap_destroy(seasick_the_cat_bmp_2);
  gbitmap_destroy(seasick_the_cat_bmp_3);
  gbitmap_destroy(seasick_the_cat_bmp_4);
  bitmap_layer_destroy(image_layer);
  
}

static void init() {
  window = window_create();
  window_set_background_color(window, COLOR_FALLBACK(GColorBlue, GColorBlack));
  window_set_click_config_provider(window, click_config_provider);
  window_set_window_handlers(window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload,
  });
  window_stack_push(window, true);
}

static void deinit() {
  window_destroy(window);
}

int main() {
  init();
  app_event_loop();
  deinit();
}
