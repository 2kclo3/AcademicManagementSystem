#pragma once
#pragma warning(disable:28159)

#ifndef _UI_H_
#define _UI_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <graphics.h>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <sysinfoapi.h>
#include <tchar.h>
#include "student.h"
#include "course.h"
#include "file.h"




class Button {
private:
	int x, y;
	int width, height;
	const wchar_t* text;
	COLORREF bkColor;
	COLORREF textColor;
	bool hovered;
	bool pressed;

public:
	Button(int _x, int _y, int _width, int _height, const wchar_t* _text, COLORREF _bkColor, COLORREF _textColor) {
		x = _x;
		y = _y;
		width = _width;
		height = _height;
		text = _text;
		bkColor = _bkColor;
		textColor = _textColor;
		hovered = false;
		pressed = false;
		draw();
	}

	void draw() {
		settextstyle(height / 2, 0, L"΢���ź�");
		setfillcolor(bkColor); //���ð�ť����
		if (hovered) {
			setfillcolor(RGB(GetRValue(bkColor) + 30, GetGValue(bkColor) + 30, GetBValue(bkColor) + 30)); //��ť��ͣ����
			if (pressed) {
				setfillcolor(RGB(GetRValue(bkColor) + 50, GetGValue(bkColor) + 50, GetBValue(bkColor) + 50)); //��ť���±���
			}
		}
		solidroundrect(x, y, x + width, y + height, height, height); //���ư�ť
		int textX = x + (width - textwidth(text)) / 2;
		int textY = y + (height - textheight(text)) / 2;
		settextcolor(textColor); //�ı���ɫ
		setbkmode(TRANSPARENT); //�ı�����͸��
		outtextxy(textX, textY, text); //�����ı�
	}

	bool mouseClick(const ExMessage& msg) {
		switch (msg.message)
		{
		case WM_MOUSEMOVE:
			if (isHovered(msg.x, msg.y)) {
				hovered = true;
			}
			else {
				hovered = false;
			}
			break;
		case WM_LBUTTONDOWN:
			if (isHovered(msg.x, msg.y)) {
				pressed = true;
			}
			break;
		case WM_LBUTTONUP:
			if (isHovered(msg.x, msg.y) && pressed == true) {
				pressed = false;
				draw();
				return true;
			}
			pressed = false;
			break;
		default:
			break;
		}
		draw();
		return false;
	}
private:
	bool isHovered(int mouseX, int mouseY) const {
		return (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);
	}
};


class Text {
private:
	int x;
	int y;
public:
	wchar_t text[512];
	int size;
	COLORREF color;
	Text(int _x, int _y, const wchar_t* _text, int _size, COLORREF _color) {
		x = _x;
		y = _y;
		_tcscpy(text, _text);
		size = _size;
		color = _color;
		draw();
	}
	void draw() {
		setbkmode(TRANSPARENT);
		settextcolor(color);
		settextstyle(size, 0, L"΢���ź�");
		outtextxy(x, y, text);

	}

};


class TextBox {
private:
	int x, y;
	int width, height;
	wchar_t hintText[512];
	bool isInput;
	bool hovered;
	COLORREF defaultColor;
	COLORREF inputColor;
	COLORREF hoveredColor;
	COLORREF borderColor;
	COLORREF textColor;

public:
	wchar_t text[512];
	TextBox(int _x, int _y, int _width, const wchar_t* _hintText, const wchar_t* _text) {
		x = _x;
		y = _y;
		width = _width;
		height = 50;
		_tcscpy(text, _text);
		_tcscpy(hintText, _hintText);
		isInput = false;
		hovered = false;
		defaultColor = RGB(33, 39, 32);
		inputColor = RGB(55, 61, 53);
		hoveredColor = RGB(69, 73, 67);
		borderColor = RGB(191, 202, 185);
		textColor = WHITE;
		//draw();
	}
	void draw() {
		//while (true) {

		// �ı���
		settextstyle(22, 0, L"΢���ź�");
		int textHeight = textheight(L"|");
		clearrectangle(x, y, x + width, y + height);
		setlinecolor(borderColor); //�߿���ɫ
		if (isInput) {
			setfillcolor(inputColor); //����ʱ�����ɫ
		}
		else if (hovered) {
			setfillcolor(hoveredColor); //�������ʱ�����ɫ
		}
		else {
			setfillcolor(defaultColor); //Ĭ�������ɫ
		}
		fillroundrect(x, y, x + width, y + height, height - 3, height - 3); //����

		// �ı�
		settextcolor(textColor);
		settextstyle((int)(height / 2.2), 0, L"΢���ź�");
		setbkmode(TRANSPARENT);
		if (!_tcscmp(text, L"")) {
			outtextxy(x + 20, y + (height - textHeight) / 2, hintText);
		}
		else {
			outtextxy(x + 15, y + (height - textHeight) / 2, text);
		}

		// ���
		if (isInput) {
			DWORD clock = GetTickCount();
			if (clock % 1000 < 500) {
				setlinecolor(WHITE); //�����ɫ
				line(x + 16 + textwidth(text), y - 2 + (height - textHeight) / 2, x + 16 + textwidth(text), y + 2 + height - (height - textHeight) / 2);
			}
			else {
				setlinecolor(inputColor);
				line(x + 16 + textwidth(text), y - 2 + (height - textHeight) / 2, x + 16 + textwidth(text), y + 2 + height - (height - textHeight) / 2);

			}
		}
		//}

	}
	void onMessage(ExMessage& msg) {
		size_t len = _tcslen(text);
		switch (msg.message)
		{
		case WM_MOUSEMOVE:
			if (isHovered(msg.x, msg.y)) {
				hovered = true;
			}
			else {
				hovered = false;
			}
			break;
		case WM_LBUTTONDOWN:
			if (isHovered(msg.x, msg.y)) {
				isInput = true;
			}
			else {
				isInput = false;
			}
			break;
		case WM_CHAR:
			if (isInput) {
				switch (msg.ch)
				{

				case '\b':
					if (len > 0) {
						text[len - 1] = '\0';
					}
					break;
				case '\r':
				case '\n':
					isInput = false;
					break;
				default:
					//printf(L"press:%c\n", msg.ch);
					if (len < 512 - 1 && textwidth(text) < width - 30) {
						text[len++] = msg.ch;
						text[len] = '\0';
						//printf(L"%d\n", textwidth(text));
					}
					break;
				}
			}
		default:
			break;
		}

	}
private:
	bool isHovered(int mouseX, int mouseY) const {
		return (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height);
	}

};


class Table {
private:
	int x, y;
	int width, height;
	int offset;
	int maxRow;
	int colWidth[20] = {0};
	int selectedRow;
	wchar_t** data;

public:
	Table(int _x, int _y, int _width, int _height, wchar_t**& _data) {
		x = _x;
		y = _y;
		width = _width;
		height = _height;
		data = _data;
		offset = 0;
		selectedRow = -1;
		maxRow = -1;
	}
	void draw() {}
	void calculateColWidth() {}
	void calculateMaxRow() {}
	void onScroll(ExMessage& msg) {}
};







void showxy(ExMessage& msg);
void testUI();
void loginUI();
void menuUI();
void allStuUI();
void StuUI();
void allCrsUI();
void CrsUI();
void allQualityUI();
void allQualityUI();
void changeMajorUI();
void settingsUI();







void printStu(const List StuList);


void printCrs(const Cpnode CrsList);



///*
//��ʾҳ��
//���ã���ʾҳ��
//������ҳ������
//���أ�ҳ����
//*/
//wchar_t* show_page(wchar_t* page_name);


/*
��ʾ�����Ϣ
���ã���ʾ�����Ϣ
����������ͷ�ڵ�,�������
���أ���
*/
//void show_sheet(List* plist, int sheet_type);







#endif
