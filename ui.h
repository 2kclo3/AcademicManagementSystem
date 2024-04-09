#pragma once
#pragma warning(disable:28159)

#ifndef _UI_H_
#define _UI_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <graphics.h>
#include <string>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <sysinfoapi.h>
#include <tchar.h>
#include <math.h>
#include <time.h>
#include "student.h"
#include "course.h"
#include "file.h"
#include "io.h"

using namespace std;



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
	Button(int _x, int _y, int _width, int _height, const wchar_t* _text, int style) {
		x = _x;
		y = _y;
		width = _width;
		height = _height;
		text = _text;
		if (style == 1) {
			bkColor = RGB(191, 202, 185);
			textColor = RGB(42, 51, 40);
		}
		else if (style == 0) {
			bkColor = RGB(73, 78, 70);
			textColor = RGB(200, 198, 195);
		}
		hovered = false;
		pressed = false;
		settextstyle(height / 2, 0, L"微软雅黑");
		draw();
	}

	void draw() {
		settextstyle(height / 2, 0, L"微软雅黑");
		setfillcolor(bkColor); //设置按钮背景
		if (hovered) {
			setfillcolor(RGB(GetRValue(bkColor) + 30, GetGValue(bkColor) + 30, GetBValue(bkColor) + 30)); //按钮悬停背景
			if (pressed) {
				setfillcolor(RGB(GetRValue(bkColor) + 50, GetGValue(bkColor) + 50, GetBValue(bkColor) + 50)); //按钮按下背景
			}
		}
		solidroundrect(x, y, x + width, y + height, height, height); //绘制按钮
		int textX = x + (width - textwidth(text)) / 2;
		int textY = y + (height - textheight(text)) / 2;
		settextcolor(textColor); //文本颜色
		setbkmode(TRANSPARENT); //文本背景透明
		outtextxy(textX, textY, text); //绘制文本
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

	void move(int _x, int _y) {
		setfillcolor(getbkcolor());
		solidrectangle(x, y, x + width, y + height);
		x = _x;
		y = _y;
		draw();
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
	wchar_t text[512];
public:
	int size;
	COLORREF color;
	Text(int _x, int _y, const wchar_t* _text, int _size) {
		x = _x;
		y = _y;
		_tcscpy(text, _text);
		size = _size;
		color = RGB(228, 226, 223);
		settextstyle(size, 0, L"微软雅黑");
		draw();
	}
	void draw() {
		setbkmode(TRANSPARENT);
		settextcolor(color);
		settextstyle(size, 0, L"微软雅黑");
		outtextxy(x, y, text);

	}
	void setText(const wchar_t* _text) {
		setfillcolor(getbkcolor());
		settextstyle(size, 0, L"微软雅黑");
		solidrectangle(x, y, x + textwidth(text), y + textheight(text));
		_tcscpy(text, _text);
		draw();
	}

	void move(int _x, int _y) {
		setfillcolor(getbkcolor());
		settextstyle(size, 0, L"微软雅黑");
		solidrectangle(x, y, x + textwidth(text), y + textheight(text));
		x = _x;
		y = _y;
		draw();
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
		if (wcscmp(_text, L"") == NULL) {
			settextstyle(22, 0, L"微软雅黑");
		}
		else {
			settextstyle((int)(height / 2.2), 0, L"微软雅黑");
		}
		//draw();
	}
	void draw() {
		//while (true) {

		// 文本框
		settextstyle(22, 0, L"微软雅黑");
		int textHeight = textheight(L"|");
		clearrectangle(x, y, x + width, y + height);
		setlinecolor(borderColor); //边框颜色
		if (isInput) {
			setfillcolor(inputColor); //输入时填充颜色
		}
		else if (hovered) {
			setfillcolor(hoveredColor); //鼠标悬浮时填充颜色
		}
		else {
			setfillcolor(defaultColor); //默认填充颜色
		}
		fillroundrect(x, y, x + width, y + height, height - 3, height - 3); //绘制

		// 文本
		settextcolor(textColor);
		settextstyle((int)(height / 2.2), 0, L"微软雅黑");
		setbkmode(TRANSPARENT);
		if (!_tcscmp(text, L"")) {
			outtextxy(x + 20, y + (height - textHeight) / 2, hintText);
		}
		else {
			outtextxy(x + 15, y + (height - textHeight) / 2, text);
		}

		// 光标
		if (isInput) {
			DWORD clock = GetTickCount();
			if (clock % 1000 < 500) {
				setlinecolor(WHITE); //光标颜色
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
					settextstyle((int)(height / 2.2), 0, L"微软雅黑");
					if (len < 512 - 1 && textwidth(text) < width - 35) {
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
	void move(int _x, int _y) {
		setfillcolor(getbkcolor());
		solidrectangle(x, y, x + width, y + height);
		x = _x;
		y = _y;
		draw();
	}
	void clear() {
		wcscpy(text, L"");
		draw();
	}
	void setText(const wchar_t* _text) {
		wcscpy(text, _text);
		draw();
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
	vector<int> colWidth;
	int selectedRow;
	vector<vector<wstring>> data;
	COLORREF bkColor;
	COLORREF textColor;
	int scollBarHeight;

public:
	bool canChange;
	Table(int _x, int _y, int _width, int _height, const vector<vector<wstring>>& _data) {
		x = _x;
		y = _y;
		width = _width;
		height = _height;
		canChange = true;
		data = _data;
		bkColor = RGB(55, 61, 53);
		textColor = WHITE;
		offset = 0;
		selectedRow = 0;
		maxRow = 0;
		calculateColWidth();
		calculateMaxRow();
		//printf("%d\n", maxRow);
		scollBarHeight = (data.size() > maxRow) ? 1.0 * maxRow / data.size() * height : height;
		draw();
	}

	void draw() {

		setfillcolor(bkColor);
		setlinecolor(WHITE);
		if (scollBarHeight != height) {
			fillroundrect(x + width + 5, y, x + width + 15, y + height, 10, 10); // 滚动条外框

			// 滚动条
			setfillcolor(WHITE);
			fillroundrect(x + width + 8,
				3 + y + 1.0 * offset / data.size() * height,
				x + width + 12,
				-3 + y + 1.0 * offset / data.size() * height + scollBarHeight,
				4, 4);
		}
		else {
			solidrectangle(x + width + 5, y, x + width + 15, y + height); // 清除滚动条
		}
		setfillcolor(bkColor);
		fillroundrect(x, y, x + width, y + height, 10, 10); // 表格外框

		//int textHeight = textheight(data[0][0].c_str());
		int textHeight = height / maxRow;


		// 选中行高亮
		if (offset < selectedRow && offset + maxRow > selectedRow) {
			setfillcolor(RGB(GetRValue(bkColor) + 30, GetGValue(bkColor) + 30, GetBValue(bkColor) + 30));
			fillrectangle(x + 1, 1 + y + (selectedRow - offset) * textHeight, x + width - 1, -1 + y + (selectedRow - offset + 1) * textHeight);
		}

		setlinecolor(WHITE);

		// 行
		int ry = y;
		for (int r = 0; r < min(maxRow, (int)data.size() - offset); r++) {

			ry += textHeight;
			if (r != min(maxRow, (int)data.size() - offset) - 1) {
				line(x, ry, x + width, ry);
			}

			// 列
			int cx = x;
			if (!r) {
				// 表头（默认表头最长）
				for (int c = 0; c < data[0].size(); c++) {
					cx += colWidth[c];
					if (c != data[0].size() - 1) {
						line(cx, y, cx, y + height);
					}
					setbkmode(TRANSPARENT);
					settextcolor(textColor);
					settextstyle(30, 0, L"微软雅黑");
					outtextxy(cx - colWidth[c] + 5, ry - textHeight + (textHeight - textheight(data[0][0].c_str())) / 2, data[0][c].c_str());
				}
			}
			else {
				// 数据
				for (int c = 0; c < data[r + offset].size(); c++) {
					cx += colWidth[c];
					setbkmode(TRANSPARENT);
					settextcolor(textColor);
					int textSize = 28;
					//while (colWidth[c] < textwidth(data[r + offset][c].c_str())) {
					//	textSize -= 10;
					//	settextstyle(textSize, 0, L"微软雅黑");
					//}
					//settextstyle(textSize, 0, L"微软雅黑");
					//if (textwidth(data[r + offset][c].c_str()) > colWidth[c]) {
					//	wstring tempText = data[r + offset][c].substr(0, colWidth[c] / textwidth(L"一" - 4)) + L"...";
					//	outtextxy(cx - colWidth[c] + 5, ry - textHeight + (textHeight - textheight(data[0][0].c_str())) / 2, tempText.c_str());
					//}
					//else {
						outtextxy(cx - colWidth[c] + 5, ry - textHeight + (textHeight - textheight(data[0][0].c_str())) / 2, data[r + offset][c].c_str());
					//}
				}
			}
		}
	}
	void calculateColWidth() { //计算每列宽度
		colWidth.clear();
		if (!data.empty()) {
			colWidth.resize(data[0].size(), 0);
			for (vector<wstring> rowData : data) {
				for (int colNum = 0; colNum < rowData.size(); colNum++) {
					int maxWidth = textwidth(rowData[colNum].c_str());
					if (maxWidth > colWidth[colNum]) {
						colWidth[colNum] = maxWidth;
					}
				}
			}

			int sumWidth = 0;
			for (auto it : colWidth) {
				sumWidth += it;
			}
			for (auto& it : colWidth) {
				it = (float)it / sumWidth * width;
			}
		}
	}
	void calculateMaxRow() { // 计算最大行数
		settextstyle(30, 0, L"微软雅黑");
		//int times = 0;
		//for (int r = 0; r < data.size(); r++) {
		//	for (int c = 0; c < data[r].size(); c++) {
		//		times = max(times, textwidth(data[r][c].c_str()) / colWidth[c]);
		//		printf("%d\n", times);
		//	}
		//}
		maxRow = height / textheight(data[0][0].c_str());
		height = maxRow * textheight(data[0][0].c_str());
	}
	void onMouse(ExMessage& msg) {
		if (isHovered(msg.x, msg.y)) {
			switch (msg.message)
			{
			case WM_MOUSEWHEEL:
				if (msg.wheel > 0 && offset > 0) { //向上滑
					offset--;
				}
				else if (msg.wheel < 0 && offset < (int)data.size() - maxRow) { //向下滑
					offset++;
				}
				break;
			case WM_LBUTTONDOWN: {
				if (canChange) {
					int Rselect = int(1.0 * (msg.y - y) / height * maxRow);
					if (Rselect != 0) {
						if (selectedRow == Rselect + offset) {
							selectedRow = 0;
						}
						else {
							selectedRow = Rselect + offset;
						}
					}
					//printf("%d\n", selectedRow);
				}
				break;
			}
			default:
				break;
			}
		}
		draw();
	}
	int getSelectedRow() {
		return (selectedRow < data.size()) ? selectedRow : 0;
	}
	void setData(const vector<vector<wstring>>& _data) {
		if (canChange) {
			data = _data;
			offset = 0;
			selectedRow = 0;
			calculateColWidth();
			//calculateMaxRow();
			scollBarHeight = (data.size() > maxRow) ? 1.0 * maxRow / data.size() * height : height;
			draw();
		}
	}
	void move(int _x, int _y) {
		setfillcolor(getbkcolor());
		solidrectangle(x, y, x + width, y + height + 20);
		x = _x;
		y = _y;
		draw();
	}

private:
	bool isHovered(int mouseX, int mouseY) const {
		return (mouseX >= x && mouseX <= x + width + 15 && mouseY >= y && mouseY <= y + height);
	}
};







void showxy(ExMessage& msg);
void testUI();
void loginUI();
void menuUI();
void allStuUI();
void StuUI(Node* Crs,List allStuList, wchar_t* pname, int* pid);
void allCrsUI();
void CrsUI(Cpnode cphead, Cpnode cplist);
void allQualityUI();
void allQualityUI();
void changeMajorUI();
void settingsUI();







void printStu(const List StuList);


void printCrs(const Cpnode CrsList);


bool showAllStuTest(const List StuList, vector<vector<std::wstring>>& data, const wchar_t* searchTerm);



///*
//显示页面
//作用：显示页面
//参数：页面名称
//返回：页面名
//*/
//wchar_t* show_page(wchar_t* page_name);


/*
显示表格信息
作用：显示表格信息
参数：链表头节点,表格类型
返回：空
*/
//void show_sheet(List* plist, int sheet_type);







#endif
