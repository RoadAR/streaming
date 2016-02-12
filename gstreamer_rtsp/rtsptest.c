#include <gst/gst.h>
#include <gst/rtsp-server/rtsp-server.h>
#include <string.h>

int main (int argc, char *argv[])
{
  GMainLoop *loop;
  GstRTSPServer *server;
  GstRTSPMediaMapping *mapping;
  GstRTSPMediaFactory *factory;

  if (argc == 1) {
    printf("USAGE: rtsptest <file.avi>\n");
    return 1;
  }

  printf("Playing %s on 0.0.0.0:5554/jpeg\n", argv[1]);

  gst_init(&argc, &argv);
  loop = g_main_loop_new(NULL, FALSE);
  server = gst_rtsp_server_new();
  gst_rtsp_server_set_address(server, "0.0.0.0");
  gst_rtsp_server_set_service(server, "5554");
  mapping = gst_rtsp_server_get_media_mapping(server);
  factory = gst_rtsp_media_factory_new();

  char *init;
  asprintf(&init, "( filesrc location=%s ! avidemux ! rtpjpegpay name=pay0 pt=96 )", argv[1]);

  gst_rtsp_media_factory_set_launch(factory, init);

  gst_rtsp_media_factory_set_shared(factory, TRUE);
  gst_rtsp_media_mapping_add_factory(mapping, "/jpeg", factory);
  g_object_unref(mapping);
  gst_rtsp_server_attach(server, NULL);
  g_main_loop_run(loop);

  return 0;
}
