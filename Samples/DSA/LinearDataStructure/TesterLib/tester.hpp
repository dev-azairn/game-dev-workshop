#ifndef TESTER_HPP
#define TESTER_HPP
#pragma once
#include <iostream>
#include <optional>
void arrayTester();
void dynamicArrayTester();
void singlyLinkedListTester();
void doublyLinkedListTester();
void circularLinkedListTester();
void staticStackTester();
void dynamicStackTester();
void staticQueueTester();
void dynamicQueueTester();
void sizePrinter(int size);
void algochecker(bool returnValue);
template <typename T>
void returnchecker(std::optional<T> returnValue);
#include "testerFunction.inl"
#endif