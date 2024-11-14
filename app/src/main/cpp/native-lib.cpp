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
    TelloClientUDP Tello("192.168.10.1");
    return env->NewStringUTF(Tello.Avant(50).c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_drone_MainActivity_ModeCommande(JNIEnv *env, jobject thiz) {
    // TODO: implement ModeCommande()
    TelloClientUDP Tello("192.168.10.1");
    return env->NewStringUTF(Tello.ModeCommande().c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_drone_MainActivity_Droite(JNIEnv *env, jobject thiz) {
    // TODO: implement Droite()
    TelloClientUDP Tello("192.168.10.1");
    return env->NewStringUTF(Tello.Droite(50).c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_drone_MainActivity_Reculer(JNIEnv *env, jobject thiz) {
    // TODO: implement Reculer()
    TelloClientUDP Tello("192.168.10.1");
    return env->NewStringUTF(Tello.Arriere(50).c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_drone_MainActivity_Decoller(JNIEnv *env, jobject thiz) {
    // TODO: implement Decoller()
    TelloClientUDP Tello("192.168.10.1");
    return env->NewStringUTF(Tello.Decoller().c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_drone_MainActivity_Atterrir(JNIEnv *env, jobject thiz) {
    // TODO: implement Atterrir()
    TelloClientUDP Tello("192.168.10.1");
    return env->NewStringUTF(Tello.Atterrir().c_str());

}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_drone_MainActivity_Gauche(JNIEnv *env, jobject thiz) {
    // TODO: implement Gauche()
    TelloClientUDP Tello("192.168.10.1");
    return env->NewStringUTF(Tello.Gauche(50).c_str());

}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_drone_MainActivity_Monter(JNIEnv *env, jobject thiz) {
    // TODO: implement Monter()
    TelloClientUDP Tello("192.168.10.1");
    return env->NewStringUTF( Tello.Monter(50).c_str());

}