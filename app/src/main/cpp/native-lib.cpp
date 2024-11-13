#include <jni.h>
#include <string>
#include "TelloClientUDP.h"
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_drone_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());


}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_drone_MainActivity_Avancer(JNIEnv *env, jobject thiz) {
    // TODO: implement Avancer()
    TelloClientUDP Tello("172.20.21.14");
    Tello.Avant(50);
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_drone_MainActivity_ModeCommande(JNIEnv *env, jobject thiz) {
    // TODO: implement ModeCommande()
    TelloClientUDP Tello("172.20.21.14");
    Tello.ModeCommande();
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_drone_MainActivity_Droite(JNIEnv *env, jobject thiz) {
    // TODO: implement Droite()
    TelloClientUDP Tello("172.20.21.14");
    Tello.Droite(50);
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_drone_MainActivity_Reculer(JNIEnv *env, jobject thiz) {
    // TODO: implement Reculer()
    TelloClientUDP Tello("172.20.21.14");
    Tello.Arriere(50);
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_drone_MainActivity_Decoller(JNIEnv *env, jobject thiz) {
    // TODO: implement Decoller()
    TelloClientUDP Tello("172.20.21.14");
    Tello.Decoller();
}