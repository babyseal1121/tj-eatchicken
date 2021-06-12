#include<iostream>
#include<string>
#include<AudioEngine.h>
#include"Player.h"
#include"TollgateScene.h"
#include"AnimationUtil.h"
#include"myController.h"
#include"SimpleMoveController.h"
#include"ControllerListener.h"

using namespace cocos2d;

const int Front = 1;
const int Behind = 2;
const int Right = 3;
const int Left = 4;


USING_NS_CC;

Scene* TollgateScene::createScene()
{
	return TollgateScene::create();
}

bool TollgateScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();

	

	/*游戏标题图片*/
	//Sprite* titleSprite = Sprite::create();

	/*初始化背景图片*/
	initBG();//初始化背景图（地图、石头、树、边界线）
	initIF();//初始化界面（血条图、计时器、得分图、小地图）

	/*开始图*/
	initBeginning();

	/*创建主角*/
	m_player = Player::create();
	m_player->bindSprite(Sprite::create("C:\\Cocos\\POBG\\HelloWorld\\Resources\\11.png"));
    m_player->setPosition(Vec2(112, 124));
    this->addChild(m_player);


	//玩家动作
	SimpleMoveController* simpleMoveControll = SimpleMoveController::create();
	auto listenerKey = EventListenerKeyboard::create();
	listenerKey->onKeyPressed = ([=](EventKeyboard::KeyCode code, Event* event)
		{
			if (code == EventKeyboard::KeyCode::KEY_S)
			{
				m_player->stopAllActions();
				//simpleMoveControll->setXSpeed(0);
				//simpleMoveControll->setYSpeed(-1);
				auto moveTo = MoveTo::create(0.5, Vec2(m_player->getPositionX(), m_player->getPositionY()-1.85));
				m_player->runAction(moveTo);
				//玩家动画
				m_player->run(1);
			}
			else if (code== EventKeyboard::KeyCode::KEY_W)
			{
				m_player->stopAllActions();
				auto moveTo = MoveTo::create(0.5, Vec2(m_player->getPositionX(), m_player->getPositionY()+35));
				m_player->runAction(moveTo);
				//玩家动画
				m_player->run(2);
			}
			else if (code == EventKeyboard::KeyCode::KEY_D)
			{
				m_player->stopAllActions();
				auto moveTo = MoveTo::create(0.5, Vec2(m_player->getPositionX()+35, m_player->getPositionY()));
				m_player->runAction(moveTo);
				//玩家动画
				m_player->run(3);
			}
			else if (code == EventKeyboard::KeyCode::KEY_A)
			{
				m_player->stopAllActions();
				auto moveTo = MoveTo::create(0.5, Vec2(m_player->getPositionX()-1.85, m_player->getPositionY()));
				m_player->runAction(moveTo);
				//玩家动画
				m_player->run(4);
			}

		});

	auto dispatcher = Director::getInstance()->getEventDispatcher();

	//添加到事件分发器
	dispatcher->addEventListenerWithSceneGraphPriority(listenerKey, this);
	
		/*控制器要添加到场景中才能让update调用*/
		this->addChild(simpleMoveControll);

		/*设置控制器到主角身上*/
		m_player->setController(simpleMoveControll);
    
	this->scheduleUpdate();//跑动地图
	return true;
   
}


//跑动地图更新
void TollgateScene::update(float delta)
{
	//int posX1=Small_map
}

/*回调函数0*/
/*void TollgateScene::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


//}

