--- avidemux_core/ADM_core/src/ADM_folder_linux.cpp.orig	2026-08-25 22:30:39 UTC
+++ avidemux_core/ADM_core/src/ADM_folder_linux.cpp
@@ -42,7 +42,7 @@ static std::string canonize(const std::string &in)
 static std::string canonize(const std::string &in)
 {
     std::string out;
-    char *simple2=canonicalize_file_name(in.c_str());
+    char *simple2=realpath(in.c_str(),nullptr);
     if(simple2)
     {
         out=std::string(simple2);
