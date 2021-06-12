//#include "HelloWorldScene.h"
#include<iostream>
#include<string>
#include<AudioEngine.h>
//#include"D:\cocos\Projects\HelloWorld\win32-build\Gamemap.h"
//#include"D:\cocos\Projects\HelloWorld\win32-build\Monster.h"
#include"Player.h"
//#include"Entity.h"
#include"TollgateScene.h"

using namespace cocos2d;

USING_NS_CC;

void TollgateScene::initBG()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//大地图
	start_Page = Sprite::create("C:\\Cocos\\POBG\\HelloWorld\\Resources\\big2xx.png");
	start_Page->setPosition(0, 0);
	this->addChild(start_Page, 0);



	//边界线
	border1 = Sprite::create("C:\\Cocos\\POBG\\HelloWorld\\Resources\\border.png");
	border1->setPosition(240, 10);
	border1->setTag(50);
	//this->addChild(border1);

	border2 = Sprite::create("C:\\Cocos\\POBG\\HelloWorld\\Resources\\border2.png");
	border2->setPosition(40, 160);
	border2->setTag(50);
	//this->addChild(border2);

	border3 = Sprite::create("C:\\Cocos\\POBG\\HelloWorld\\Resources\\border2.png");
	border3->setPosition(440, 160);
	border3->setTag(50);
	//this->addChild(border3);

	border4 = Sprite::create("C:\\Cocos\\POBG\\HelloWorld\\Resources\\border.png");
	border4->setPosition(240, 320);
	border4->setTag(50);
	//this->addChild(border4);

	//石头
	box = Sprite::create("C:\\Cocos\\POBG\\HelloWorld\\Resources\\bocket.png");
	box->setPosition(Vec2(227, 260));
	box->setTag(50);
	this->addChild(box);

	tree = Sprite::create("C:\\Cocos\\POBG\\HelloWorld\\Resources\\cao.png");
	tree->setPosition(Vec2(315, 380));
	tree->setTag(50);
	this->addChild(tree);

}

void TollgateScene::initIF()
{
	//小地图
	Small_map = Sprite::create("C:\\Cocos\\POBG\\HelloWorld\\Resources\\big2.png");
	Small_map->setPosition(453 - Small_map->getContentSize().width / 2, 320 - Small_map->getContentSize().height / 2);
	this->addChild(Small_map);

	//血条
	m_blood = Sprite::create("C:\\Cocos\\POBG\\HelloWorld\\Resources\\blood.png");
	m_blood->setPosition(Vec2(160, 300));
	m_blood->setScale(1, 1);
	this->addChild(m_blood);

	//血条分隔线
	bloodout = Sprite::create("C:\\Cocos\\POBG\\HelloWorld\\Resources\\bloodout.png");
	bloodout->setPosition(Vec2(160, 300));
	this->addChild(bloodout);

	//血条标签
	blood_label = Label::create();
	blood_label->setString("Blood Volume");
	blood_label->setColor(Color3B(0, 0, 0));
	blood_label->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	blood_label->setPosition(Vec2(75, 300));
	this->addChild(blood_label);

	/*score_label = Label::create();
	score_label->setString("Your Score");
	score_label->setColor(Color3B(0, 0, 0));
	score_label->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	score_label->setPosition(Vec2(75, 270));
	this->addChild(score_label);*/

	time_label = Label::create();
	time_label->setString("Time");
	time_label->setColor(Color3B(0, 0, 0));
	time_label->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	time_label->setPosition(Vec2(260, 300));
	this->addChild(time_label);

	black1 = Sprite::create("C:\\Cocos\\POBG\\HelloWorld\\Resources\\black.png");
	black1->setPosition(453 - black1->getContentSize().width / 2, 320 - black1->getContentSize().height / 2);
	black1->setOpacity(80);
	this->addChild(black1);
}
void TollgateScene::initBeginning()
{
	POBG = Label::create();
	POBG->setString("POBG");
	POBG->setScale(5);
	POBG->setColor(Color3B(3, 54, 73));
	POBG->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	POBG->setPosition(Vec2(300, 250));
	this->addChild(POBG);

	STARTGAME = Label::create();
	STARTGAME->setString("START GAME");
	STARTGAME->setScale(3);
	STARTGAME->setColor(Color3B(3, 22, 52));
	STARTGAME->enableShadow(Color4B(0, 0, 0, 0), Size(-0.5, -0.5), 1);
	STARTGAME->setPosition(Vec2(300, 175));
	//auto physicsBody_start = PhysicsBody::createBox(STARTGAME->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
	//physicsBody_start->setDynamic(false);
	//physicsBody_start->setContactTestBitmask(0xFFFFFFFF);
	//STARTGAME->setPhysicsBody(physicsBody_start);
	STARTGAME->setTag(70);
	this->addChild(STARTGAME);

	CREATEROOM = Label::create();
	CREATEROOM->setString("CREATE ROOM");
	CREATEROOM->setScale(2);
	CREATEROOM->setColor(Color3B(138, 151, 123));
	CREATEROOM->enableShadow(Color4B(0, 0, 0, 0), Size(-0.5, -0.5), 1);
	CREATEROOM->setPosition(Vec2(300, 125));
	CREATEROOM->addChild(CREATEROOM);

	ENTERROOM = Label::create();
	ENTERROOM->setString("ENTER ROOM");
	ENTERROOM->setScale(2);
	ENTERROOM->setColor(Color3B(138, 151, 123));
	ENTERROOM->enableShadow(Color4B(0, 0, 0, 0), Size(-0.5, -0.5), 1);
	ENTERROOM->setPosition(Vec2(300, 75));
	this->addChild(ENTERROOM);

	Exit = Label::create();
	Exit->setString("Exit");
	Exit->setScale(1.5);
	Exit->setColor(Color3B(3, 22, 52));
	Exit->enableShadow(Color4B(0, 0, 0, 255), Size(-0.5, -0.5), 1);
	Exit->setPosition(Vec2(400, 40));
	//auto physicsBody_end = PhysicsBody::createBox(Exit->getContentSize(), PhysicsMaterial(0.0f, 0.0f, 0.0f));
	//physicsBody_end->setDynamic(false);
	//physicsBody_end->setContactTestBitmask(0xFFFFFFFF);
	//Exit->setPhysicsBody(physicsBody_end);
	Exit->setTag(80);
	this->addChild(Exit);
}
