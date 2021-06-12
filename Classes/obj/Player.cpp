//#include "HelloWorldScene.h"
#include "cocos2d.h"
#include<iostream>
#include<string>
#include<AudioEngine.h>
#include"Player.h"

using namespace std;

USING_NS_CC;
Player::Player(){}
 
Player::~Player(){}

bool Player::init()
{
	return true;
}

//人物动画，包括上下左右四个方向的移动
//重写了第一版，通过图片打包使程序更加简洁
void Player::run(int index)
{
    SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
    if(index==1)
        frameCache->addSpriteFramesWithFile("C:\\Cocos\\POBG\\HelloWorld\\Resources\\front.plist", "C:\\Cocos\\POBG\\HelloWorld\\Resources\\front.png");
    else if(index == 2)
        frameCache->addSpriteFramesWithFile("C:\\Cocos\\POBG\\HelloWorld\\Resources\\behind.plist", "C:\\Cocos\\POBG\\HelloWorld\\Resources\\behind.png");
    else if (index == 3)
        frameCache->addSpriteFramesWithFile("C:\\Cocos\\POBG\\HelloWorld\\Resources\\right.plist", "C:\\Cocos\\POBG\\HelloWorld\\Resources\\right.png");
    else if (index == 4)
        frameCache->addSpriteFramesWithFile("C:\\Cocos\\POBG\\HelloWorld\\Resources\\left.plist", "C:\\Cocos\\POBG\\HelloWorld\\Resources\\left.png");
    SpriteFrame* frame = NULL;
    Vector<SpriteFrame*>frameList;

    for (int i = 1; i < 5; i++)
    {
        frame = frameCache->getSpriteFrameByName(StringUtils::format("%d%d.png",index, i));
        frameList.pushBack(frame);
    }

    Animation* animation = Animation::createWithSpriteFrames(frameList);
    animation->setLoops(1);
    animation->setRestoreOriginalFrame(true);
    animation->setDelayPerUnit(0.2f);

    Animate* animate = Animate::create(animation);
    //m_sprite->stopAction(animate);
    m_sprite->runAction(animate);
}

void Player::action()
{
    
}


