//游戏主角类的绘制
#ifndef __Player_H__
#define __Player_H__

#include "cocos2d.h"
#include"Entity.h"
//#include "HelloWorldScene.h"
#include<string>
using namespace cocos2d;

#define JUMP_ACTION_TAG 1
class Player :public Entity
{
public:Player();
      ~Player();
      CREATE_FUNC(Player);
      virtual bool init();
      void run(int index);
      void action();

    Animate* animate1;
    Animate* animate2;
    Animate* animate3;
    Animate* animate4;
private:
    int m_iScore;         //分数
    EventListenerKeyboard* keyListener = EventListenerKeyboard::create();//动作
    
    //Text* m_scorelab;    //分数标签
    //LoadingBar m_hpbar; //血量条
};
/*class Player : public cocos2d::Sprite
{
public:
    Player(cocos2d::Sprite* a) {
        //printf("\na:%d", a);
    }
    cocos2d::Sprite* get_player()//获取某个精灵的值 
    {
        return _player;
    }
    void set_player()
    {
        //_player= cocos2d::Sprite::create("C:\\Cocos\\POBG\\HelloWorld\\Resources\\5.png");//设置图片
        _player->setPosition(cocos2d::Vec2(112, 124));//设置玩家初始位置
    }
private:
	cocos2d::Sprite* _player ;
};*/

#endif
//继承于精灵
/*class Player :public cocos2d::Sprite
{
public:
    Player(const string* name);
    ~Player();
public:
    void hookRotateAction(float);
};*/
