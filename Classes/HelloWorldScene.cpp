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
	// テクスチャファイル名を指定して、スプライトを作成
	sprite = Sprite::create("kuma.png");
	// シーングラフにつなぐ
	this->addChild(sprite);

	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	sprite->setScale(0.2f);  //大きさの変更
	//sprite->setVisible(false);  //見えなくする（描画を飛ばす）
	/*0xffと255は同じ*/
	//sprite->setOpacity(128);     //不透明度
	//
	//
	//sprite->setAnchorPoint(Vec2(0, 1));
	//sprite->setRotation(135.0f);
	//
	//
	//sprite->setColor(Color3B(255, 0, 0));    //色の変更
	//
	//
	//sprite->setFlippedX(true);   //画像の反転(true)
	//
	//
	//sprite->setTextureRect(Rect(225, 273, 126, 167));
	//
	//
	//// テクスチャファイル名を指定して、スプライトを作成
	//sprite = Sprite::create("sample03.png");
	//// シーングラフにつなぐ
	//this->addChild(sprite);
	//
	//sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	//
	//sprite->setScale(4);
	//
	//sprite->setTextureRect(Rect(0, 64, 32, 32));

	//sp = Sprite::create("sample03.png");
	//
	//// シーングラフにつなぐ
	//this->addChild(sp);
	//
	//sp->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	//
	//sp->setScale(4);
	//sp->getTexture()->setAliasTexParameters();
	//
	//sp->setTextureRect(Rect(0, 64, 32, 32));
	//
	//sp->setOpacity(0);

	//  //////19-06-24~~~~

	MoveBy* action1 = MoveBy::create(1.0f, Vec2(400, 200));
	//EaseInOut* action2 = EaseInOut::create(action1, 2.0f);
	//ScaleBy* action1 = ScaleBy::create(1.0f,5.0f);
	//JumpTo* action1 = JumpTo::create(1.0f, Vec2(200, 100), 500.0f, 1);
	//ベジェ曲線
	//ccBezierConfig conf;
	//conf.controlPoint_1 = Vec2(800, 700);
	//conf.controlPoint_2 = Vec2(1000, 700);
	//conf.endPosition = Vec2(1000, 360);
	//BezierTo* action1 = BezierTo::create(2.0f, ccBezierConfig());
	//フェードイン
	//sprite->setOpacity(0);
	//FadeIn* action1 = FadeIn::create(1.0f);
	//FadeInは最初見えない状態にしないといけない
	//RotateBy* action1 = RotateBy::create(1.0f, 30, 30);

	//ノードに対してアクションを実行する
	sprite->runAction(action1);


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

}

