//
//  ofxSocketIO.h
//
//  Created by hugohil on 05/02/16.
//
//
#pragma once

#include "ofMain.h"
#include "ofEvents.h"
#if defined(_MSC_VER) || defined(_WIN32) || defined(WIN32) || defined(__MINGW32__)
  // Windows stuff
#else
  // Linux and OSX here
  #include <sio_client.h>
#endif
#include "ofxSocketIOData.h"

class ofxSocketIO : protected ofThread {
private :
  sio::client client;
  sio::socket::ptr socket;

  std::string currentStatus;

public :
  void setup(std::string& address);

  void onConnect();
  void onClose(sio::client::close_reason const& reason);
  void onFail();
  void onTryReconnect();

  void bindEvent(ofEvent<ofxSocketIOData&>& event, std::string eventName);

  ofEvent<void> connectionEvent;
  ofEvent<std::string> notifyEvent;

  void closeConnection();
};
