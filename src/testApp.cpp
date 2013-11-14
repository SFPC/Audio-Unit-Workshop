#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    player.setFile(ofToDataPath("Willow Beats - TAWK TAKEOUT (Tawk Tomahawk Remixed) - 08 Ocelot (Willow Beats Remix).mp3"));
    
    sampler = ofxAudioUnitSampler('aumu', 'dls ', 'appl');
    
    
    delay = ofxAudioUnit('aufx', 'dely', 'appl');
    delay.printParameterList();
//    [1] delay time [0.0001 : 2 : 1]
//    [2] feedback [-99.9 : 99.9 : 50]
    delay.setParameter(1, kAudioUnitScope_Global, 2);
    delay.setParameter(2, kAudioUnitScope_Global, 99.9);
    
    filter = ofxAudioUnit('aufx', 'filt', 'appl');
    
    player.connectTo(filter);
    input.connectTo(delay);
    
    mixer.setInputBusCount(3);
    sampler.connectTo(mixer, 0);
    filter.connectTo(mixer, 1);
    delay.connectTo(mixer, 2);
    
    mixer.connectTo(output);
    
    input.start();
    output.start();
    player.loop();
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case 'd':
            delay.showUI();
            break;
            
        case 'f':
            filter.showUI();
            break;
            
        case 's':
            sampler.showUI();
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    float pct = ofMap(x, 0, ofGetWidth(), 0.0, 1.0);
    mixer.setInputVolume(pct, 0);
    mixer.setInputVolume(1 - pct, 1);
    
//    This dynamically controls the delay time of the Delay AU with the y position of the mouse
//    float delayTime = ofMap(y, 0, ofGetHeight(), 0.0001, 2, true);
//    delay.setParameter(1, kAudioUnitScope_Global, delayTime);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    sampler.midiNoteOn(60, 127);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    sampler.midiNoteOff(60, 0);
    sampler.setProgram(ofRandom(0, 127));
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
