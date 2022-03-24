#pragma once
// Imgui Library
#include <imgui-SFML.h>
#include <imgui.h>
// SFML Library
#include <SFML/Graphics.hpp>

// Standar c++
#include <string>
#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

enum EngineMode
{
  GameDevelopment = 0,
  SecretHitlerG = 1,
};


static float
invSqrt(float _v) {
    return 1.0f / sqrt(_v);
  }

static float
sqr(float _v) {
    return _v * _v;
  }



struct Vector2F {
	float x;
	float y;
  
  //Vector2F(float _x, float _y) : x(_x), y(_y) { }
  /*
  Vector2F&
    operator+=(const Vector2F& _v) {
    *this = *this + _v;
    return *this;
  }

  Vector2F
    operator+(const Vector2F& _v) const {
    return Vector2F(x + _v.x, y + _v.y);
  }

  Vector2F&
    operator-=(const Vector2F& _v) {
    *this = *this - _v;
    return *this;
  }

  Vector2F
    operator-(const Vector2F& _v) const {
    return Vector2F(x - _v.x, y - _v.y);
  }

  void
    operator*=(const float _a) {
    x *= _a;
    y *= _a;
  }

  Vector2F
    operator*(const float _a) const {
    return Vector2F(_a * x, _a * y);
  }

  void
    operator/=(const float _a) {
    x = x / _a;
    y = y / _a;
  }

  Vector2F
    operator/(const float _a) const {
    return Vector2F(x / _a, y / _a);
  }

  float
    dot(const Vector2F& _v) const {
    return x * _v.x + y * _v.y;
  }

  float
    operator*(const Vector2F& _v) const {
    return x * _v.x + y * _v.y;
  }

  Vector2F
    cross(const Vector2F& _v) const {
    return Vector2F(x * _v.y,
      y * _v.x);
  }

  void
    operator%=(const Vector2F _v) {
    *this = cross(_v);
  }

  Vector2F
    operator%(const Vector2F& _v) const {
    return Vector2F(x * _v.y,
      y * _v.x);
  }
  */

  

  float
    sqrMagnitude() {
    return sqr(x) + sqr(y);
  }

  float
    magnitude() {
    return std::sqrt(sqrMagnitude());
  }

  void
    normalize() {
    float sqrMag = sqrMagnitude();

    if (0.0f == sqrMag) {
      return;
    }

    float normValue = invSqrt(sqrMag);
    x = x * normValue;
    y = y * normValue;
  }

  

};

