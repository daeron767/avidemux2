--- avidemux/qt4/ADM_update/src/ADM_update.cpp.orig
+++ avidemux/qt4/ADM_update/src/ADM_update.cpp
@@ -111,7 +111,8 @@
 void ADM_checkForUpdate(ADM_updateComplete *up)
 {
     
     ADMCheckUpdate *update=new ADMCheckUpdate(up);
-    QTimer::singleShot(0, update, SLOT(execute()));
+    // Qt6 workaround
+    QMetaObject::invokeMethod(update, "execute", Qt::QueuedConnection);
 }
 //EOF
