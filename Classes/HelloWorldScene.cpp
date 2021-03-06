/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "AudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	if (closeItem == nullptr ||
		closeItem->getContentSize().width <= 0 ||
		closeItem->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
		float y = origin.y + closeItem->getContentSize().height / 2;
		closeItem->setPosition(Vec2(x, y));
	}

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);


	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	if (label == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label, 1);
	}
	//乱数　移動
	{
		//乱数の初期化
		//Random rnd = new Random();と一緒
		//srand(time(nullptr));

		//for (int i = 0; i < 5; i++)
		//{
		//	sprite[i] = Sprite::create("kuma.png");
		//	this->addChild(sprite[i]);

		//	sprite[i]->setPosition(Vec2(200 * i, visibleSize.height / 2));
		//	sprite[i]->setScale(0.2f);  //大きさの変更

		//	float mx, my;
		//	mx = (float)rand() / RAND_MAX * 500 - 250;
		//	my = (float)rand() / RAND_MAX * 500 - 250;

		//	MoveBy* action1 = MoveBy::create(1.0f, Vec2(mx, my));
		//	sprite[i]->runAction(action1->clone());
		//}
	}


	//// テクスチャファイル名を指定して、スプライトを作成
	//sprite = Sprite::create("kuma.png");
	//// シーングラフにつなぐ
	//this->addChild(sprite);

	//sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	//sprite->setScale(0.2f);  //大きさの変更
	////sprite->setVisible(false);  //見えなくする（描画を飛ばす）
	///*0xffと255は同じ*/
	////sprite->setOpacity(128);     //不透明度
	////
	////
	////sprite->setAnchorPoint(Vec2(0, 1));
	////sprite->setRotation(135.0f);
	////
	////
	////sprite->setColor(Color3B(255, 0, 0));    //色の変更
	////
	////
	////sprite->setFlippedX(true);   //画像の反転(true)
	////
	////
	////sprite->setTextureRect(Rect(225, 273, 126, 167));
	////
	////
	////// テクスチャファイル名を指定して、スプライトを作成
	////sprite = Sprite::create("sample03.png");
	////// シーングラフにつなぐ
	////this->addChild(sprite);
	////
	////sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	////
	////sprite->setScale(4);
	////
	////sprite->setTextureRect(Rect(0, 64, 32, 32));

	////sp = Sprite::create("sample03.png");
	////
	////// シーングラフにつなぐ
	////this->addChild(sp);
	////
	////sp->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	////
	////sp->setScale(4);
	////sp->getTexture()->setAliasTexParameters();
	////
	////sp->setTextureRect(Rect(0, 64, 32, 32));
	////
	////sp->setOpacity(0);

	////  //////19-06-24~~~~
	{
		//MoveBy* action1 = MoveBy::create(1.0f, Vec2(400, 200));

		////EaseInOut* action2 = EaseInOut::create(action1, 2.0f);
		////ScaleBy* action1 = ScaleBy::create(1.0f,5.0f);
		////JumpTo* action1 = JumpTo::create(1.0f, Vec2(200, 100), 500.0f, 1);
		////ベジェ曲線
		////ccBezierConfig conf;
		////conf.controlPoint_1 = Vec2(800, 700);
		////conf.controlPoint_2 = Vec2(1000, 700);
		////conf.endPosition = Vec2(1000, 360);
		////BezierTo* action1 = BezierTo::create(2.0f, ccBezierConfig());
		////フェードイン
		////sprite->setOpacity(0);
		////FadeIn* action1 = FadeIn::create(1.0f);
		////FadeInは最初見えない状態にしないといけない
		////RotateBy* action1 = RotateBy::create(1.0f, 30, 30);
	}
	////ノードに対してアクションを実行する
	//sprite->runAction(action1->clone());

	//// テクスチャファイル名を指定して、スプライト2を作成
	//sprite2 = Sprite::create("21.png");
	//// シーングラフにつなぐ
	//this->addChild(sprite2);

	//sprite2->setPosition(Vec2(900, visibleSize.height / 2));
	//sprite2->setScale(0.2f);  //大きさの変更
	////MoveBy* action2 = MoveBy::create(1.0f, Vec2(400, 200));
	//////ノードに対してアクションを実行する
	//sprite2->runAction(action1->clone());


	//Actionやってみよう1
	{
		/*sprite[0] = Sprite::create("kuma.png");
		this->addChild(sprite[0]);
		sprite[0]->setPosition(Vec2(200, 100));
		sprite[0]->setScale(0.2f);
		JumpBy* action = JumpBy::create(1.0f, Vec2(300, 100), 500.0f, 1);
		sprite[0]->runAction(action->clone());

		sprite[1] = Sprite::create("21.png");
		this->addChild(sprite[1]);
		sprite[1]->setPosition(Vec2(400, 100));
		sprite[1]->setScale(0.2f);
		sprite[1]->runAction(action->clone());*/
	}
	//Actionやってみよう2

	//for (int i = 0; i < 10; i++)
	//{
	//	/*sprite[i] = Sprite::create("kuma.png");
	//	this->addChild(sprite[i]);
	//	sprite[i]->setPosition(Vec2(200 + i * 100, 100));
	//	sprite[i]->setScale(0.2f);
	//	JumpBy* action = JumpBy::create(1.0f, Vec2(300, 100), 500.0f, 1);
	//	sprite[i]->runAction(action->clone());*/
	//}

	//{
	//	//乱数の初期化
	//	//Random rnd = new Random();と一緒
	//	srand(time(nullptr));
	//
	//	for (int i = 0; i < 10; i++)
	//	{
	//		sprite[i] = Sprite::create("kuma.png");
	//		this->addChild(sprite[i]);
	//
	//		float posx;
	//		float posy;
	//		posx = (float)rand() / RAND_MAX * visibleSize.width;
	//		posy = (float)rand() / RAND_MAX * visibleSize.height;
	//
	//		sprite[i]->setPosition(Vec2(posx, posy));
	//		sprite[i]->setScale(0.2f);  //大きさの変更
	//
	//		float mx;
	//		float my;
	//		mx = (float)rand() / RAND_MAX * visibleSize.width;
	//		my = (float)rand() / RAND_MAX * visibleSize.height;
	//
	//
	//		MoveTo* action1 = MoveTo::create(1.0f, Vec2(mx,my));
	//		sprite[i]->runAction(action1->clone());
	//	}
	//}
	
#pragma region 休みの日
	//// Spriteの生成
	//Sprite* spr = Sprite::create("HelloWorld.png");
	//this->addChild(spr);
	//spr->setPosition(Vec2(visibleSize.width - 100, visibleSize.height - 100));
	//spr->setScale(0.2f);
	//
	//// 移動アクションの生成
	//MoveBy* moveLeft = MoveBy::create(1.0f, Vec2(-(visibleSize.width - 200), 0));
	//MoveBy* moveDown = MoveBy::create(1.0f, Vec2(0, -(visibleSize.height - 200)));
	//MoveBy* moveRight = MoveBy::create(1.0f, Vec2(visibleSize.width - 200, 0));
	//MoveBy* moveUp = MoveBy::create(1.0f, Vec2(0, visibleSize.height - 200));
	//
	//// 連続アクションの生成
	//Sequence* seq1 = Sequence::create(moveLeft, moveDown, moveRight, moveUp, nullptr);
	//
	//// 無限繰り返しアクションの生成
	//RepeatForever* repeat = RepeatForever::create(seq1);
	//
	//// アクションの実行
	//spr->runAction(repeat);

#pragma endregion

	//再生するとオーディオIDが割り振られる
	audioID = experimental::AudioEngine::play2d("11rsm.mp3",true,0.1f);


	DelayTime* delay = DelayTime::create(1.0f);

	//関数呼び出しアクションの作成
	//CC_CALLBACK_0　第一引数：呼び出したいメンバ関数
	//CC_CALLBACK_0　第二引数：メンバ関数を呼び出すオブジェクト
	CallFunc* callFunc =
		CallFunc::create(CC_CALLBACK_0(HelloWorld::myFunction, this));

	Sequence* seq = Sequence::create(delay, callFunc, nullptr);

	//アクションを実行
	this->runAction(seq);

	//updateが呼び出されるように
	this->scheduleUpdate();

	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::update(float delta)
{
#pragma region 四隅移動


	////ここに毎フレームしたいことを書く
	////スプライトの現在座標を取得
	//Vec2 pos;
	////現在の透明度を取得
	//float opac = sprite->getOpacity();


	////if (pos.x > 250 && pos.y >= 720 - 230)
	////{
	////	//pos.x += -5;
	////}
	////else if (pos.y > 230 && pos.x <= 250)
	////{
	////	//pos.y += -5;
	////}
	////else if (pos.x < 1280 - 250 && pos.y <= 230)
	////{
	////	//pos.x += 5;
	////}
	////else if (pos.y < 720 - 230 && pos.x >= 1280 - 250)
	////{
	////	//pos.y += 5;
	////}


	//switch (state)
	//{
	//case 0://左
	//	pos = sprite->getPosition();
	//	pos.x += -5;
	//	//移動後の座標を反映
	//	sprite->setPosition(pos);
	//
	//	if (pos.x <= 255)
	//	{
	//		state = 1;
	//	}
	//	break;

	//case 1://下
	//	pos = sprite->getPosition();
	//	pos.y += -5;
	//	sprite->setPosition(pos);
	//
	//	if (pos.y <= 235)
	//	{
	//		state = 2;
	//	}
	//	break;

	//case 2://右
	//	pos = sprite->getPosition();
	//	pos.x += 5;
	//	sprite->setPosition(pos);
	//
	//	if (pos.x >= 1280 - 255)
	//	{
	//		state = 3;
	//	}
	//	break;

	//case 3://上
	//	pos = sprite->getPosition();
	//	pos.y += 5;
	//	sprite->setPosition(pos);
	//
	//	if (pos.y >= 720 - 235)
	//	{
	//		state = 0;
	//	}
	//	break;

	//default:
	//	break;
	//}

	//if (opac > 0.0f)
	//{
	//	//sprite->setOpacity(opac - 255.0f / 300.0f);
	//}
#pragma endregion

#pragma region 左上を中心に回転
	/*rotate += 10;
	sprite->setRotation(rotate);*/
#pragma endregion

#pragma region 色を三秒で変更
	/*Color3B color = sprite->getColor();

	if (color.b < 255)
	{
		color.r -= 255.0f / 180.0f;
		color.b += 255.0f / 180.0f;

		sprite->setColor(color);
	}*/

	/*if (col > 0)
	{
		col -= 255.0f / 180.0f;
		sprite->setColor(Color3B(col, 0, 255 - col));
	}*/

#pragma endregion

#pragma region クロスフェード

	/*if (opacity > 0)
	{
		opacity -= 255.0f / 300.0f;

		sprite->setOpacity(opacity);
		sp->setOpacity(255 - opacity);
	}*/

#pragma endregion

#pragma region 往復

	//Vec2 pos;
	//switch (state)
	//{
	//case 0://左
	//	sprite->setFlippedX(true);
	//	pos = sprite->getPosition();
	//	pos.x += -5;
	//	//移動後の座標を反映
	//	sprite->setPosition(pos);

	//	if (pos.x <= 100)
	//	{
	//		state = 1;
	//	}
	//	break;
	//case 1://右
	//	sprite->setFlippedX(false);
	//	pos = sprite->getPosition();
	//	pos.x += 5;
	//	sprite->setPosition(pos);

	//	if (pos.x >= 1280 - 100)
	//	{
	//		state = 0;
	//	}
	//	break;

	//}
#pragma endregion

#pragma region パターンアニメーション
	/*sprite->setOpacity(0);
	sp->setOpacity(255);

	rec += 0.1f;
	if (rec > 2)
	{
		rec = 0;
	}
	sp->setTextureRect(Rect(64 * (int)rec, 64, 32, 32));
*/
#pragma endregion

#pragma region 音楽の停止、一時停止

	////経過時間を取得
	//unsigned int total =
	//Director::getInstance()->getTotalFrames();

	////if (total == 60) //一秒後
	////{
	////	//再生停止
	////	//experimental::AudioEngine::stop(audioID);
	////	//再生一時停止
	////	experimental::AudioEngine::pause(audioID);
	////}
	////if (total == 120)
	////{
	////	experimental::AudioEngine::resume(audioID);
	////}

	//if (total%60 == 0)
	//{
	//	if ((total/60) % 2 == 1)
	//	{
	//		experimental::AudioEngine::pause(audioID);
	//	}
	//	else
	//	{
	//		experimental::AudioEngine::resume(audioID);
	//	}
	//}

#pragma endregion

}

//任意の自作関数
void HelloWorld::myFunction()
{
	//任意の処理
	Sprite* spr = Sprite::create("21.png");
	this->addChild(spr);
	spr->setPosition(500, 500);
}

