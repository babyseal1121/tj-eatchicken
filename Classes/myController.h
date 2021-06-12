#ifndef __Controller_H__
#define __Controller_H__

#include "cocos2d.h"
#include<string>
#include"ControllerListener.h"
using namespace cocos2d; 

class myController :public Node
{
public:
	/*设置监听对象*/
	void setControllerListener(ControllerListener* controllerListener);
protected:
	ControllerListener* m_controllerListener;
};
#endif
