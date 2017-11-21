#include "ofApp.h"

int z = -2000;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    
    // this uses depth information for occlusion
    // rather than always drawing things on top of each other
    ofEnableDepthTest();
    
    // turn on smooth lighting //
    ofSetSmoothLighting(true);
    
    // this sets the camera's distance from the object
//    cam.setDistance(100);
    cam.setPosition(0, 0, 1000);
    
   
    center.set((ofGetWidth()*.5), (ofGetHeight()*.5-200), 300);
    
    
    
    // Point lights emit light in all directions //
    // set the diffuse color, color reflected from the light source //
//    pointLight.setDiffuseColor( ofColor(0.f, 255.f, 0.f));
    pointLight.setDiffuseColor( ofColor::white);

    
    // specular color, the highlight/shininess color //
    pointLight.setSpecularColor( ofColor(255.f, 255.f, 255.f));
    pointLight.setPosition(center.x, center.y, center.z);
    
    // shininess is a value between 0 - 128, 128 being the most shiny //
    material.setShininess( 100 );
    
    
    
    colorHue = ofRandom(0, 250);
    
    lightColor.setBrightness( 180.f );
    lightColor.setSaturation( 150.f );
    
    materialColor.setBrightness(250.f);
    materialColor.setSaturation(200);



}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    colorHue += .1f;
    if(colorHue >= 255) colorHue = 0.f;
    lightColor.setHue(255);
    
    radius = cos(ofGetElapsedTimef()) * 200.f + 200.f;
    
    pointLight.setDiffuseColor(lightColor);
    
    
    materialColor.setHue(100);
    // the light highlight of the material //
    material.setSpecularColor(materialColor);

}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    cam.begin();

    
    ofSetColor(pointLight.getDiffuseColor());
    ofDrawSphere(pointLight.getPosition(), 20.f);
    
    // enable lighting //
    ofEnableLighting();
    // the position of the light must be updated every frame,
    // call enable() so that it can update itself //
    pointLight.enable();
    material.begin();

    
    
    ofBackgroundGradient( ofColor( 255 ), ofColor( 128 ) );
    
    ofRotateX(-15);
    
    //fretboard
    ofFill();
    ofSetColor(ofColor::lime);
    ofDrawBox( (ofGetWidth()/2), ofGetHeight()-300, -2000, 500, 30, 5000);
    ofNoFill();
    ofSetColor(ofColor::black);
    ofDrawBox((ofGetWidth()/2), ofGetHeight()-300, -2000, 500, 30, 5000);
    
    
    //frets
    int fz = -2000;
    ofFill();
    ofSetColor(ofColor::violet);
    for(int i=0;i<13;i++){
        ofDrawBox((ofGetWidth()/2), ofGetHeight()-317, fz, 500, 10, 10);
        fz = fz+200;
    }
    
    
    //strings
//    int fz = -2000;
    ofFill();
    ofSetColor(ofColor::aquamarine);
    ofPushMatrix();
    ofRotateX(-90);
    ofTranslate(ofGetWidth()/2,1000,ofGetHeight()-317);
//    for(int i=0;i<13;i++){
    ofDrawCylinder( 0, 0, 0, 10, 3000);
//    fz = fz+200;
//    }
    ofPopMatrix();

    
    
    //target
    ofFill();
    ofSetColor(ofColor::indianRed);
    z = z+(ofGetElapsedTimef()*0.4);
    ofDrawSphere(ofGetWidth()/2, ofGetHeight()-330, z, 30);
    
    
    material.end();
    // turn off lighting //
    ofDisableLighting();
    
    ofSetColor(0, 255, 0, 100);
    ofDrawBitmapString("Hello, how can I help you today", 200, 600);

    
//    cam.end();


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
