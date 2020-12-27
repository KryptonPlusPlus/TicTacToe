#pragma once
#pragma once

class _CharRectangle
{
private:

	// Bordas simples
	const char key_single_upper_left_edge = '\xda'; // ┌
	const char key_single_upper_right_edge = '\xbf'; // ┐
	const char key_single_bottom_left_edge = '\xc0'; // └
	const char key_single_bottom_right_edge = '\xd9'; // ┘
	const char key_single_side_edge = '\xb3'; // │
	const char key_single_upper_bottom_edge = '\xc4'; // ─
	const char key_single_bottom_edge_with_dash = '\xc1'; // ┴
	const char key_single_top_edge_with_dash = '\xc2'; // ┬
	const char key_single_right_edge_with_dash = '\xc3'; // ├
	const char key_single_left_edge_with_dash = '\xb4'; // ┤
	const char key_single_cross = '\xc5'; // ┼

	// Bordas duplas
	const char key_double_upper_left_edge = '\xc9'; // ╔	
	const char key_double_upper_right_edge = '\xbb'; // ╗
	const char key_double_bottom_left_edge = '\xc8'; // ╚
	const char key_double_bottom_right_edge = '\xbc'; // ╝
	const char key_double_side_edge = '\xba'; // ║
	const char key_double_upper_bottom_edge = '\xcd'; // ═
	const char key_double_bottom_edge_with_dash = '\xca'; // ╩
	const char key_double_top_edge_with_dash = '\xcb'; // ╦
	const char key_double_right_edge_with_dash = '\xcc'; // ╠
	const char key_double_left_edge_with_dash = '\xb9'; // ╣
	const char key_double_cross = '\xce'; // ╬

	enum class TypeRectangle { CompleteSingle, CompleteDouble, OnlyLateralSingle, OnlyLateralDouble };

	TypeRectangle type_rectangle = TypeRectangle::CompleteSingle;
	int _width = 0;
	int _height = 0;

public:
	_CharRectangle();
	//CharRectangle(/*int _width, int _height*//*, TypeRectangle type_line = TypeRectangle::CompleteSingle*/);
	virtual ~_CharRectangle() {};

	// --- gets ---
	int           getWidth() { return _width; }
	int           getHeight() { return _height; }
	//TypeRectangle getTypeRectangle() { return type_rectangle; }

};

