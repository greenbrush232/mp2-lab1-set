// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : BitField(-1)
{
	MaxPower = mp;
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(-1)
{
	MaxPower = s.MaxPower;
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(-1)
{
	MaxPower = bf.GetLength();
}

TSet::operator TBitField()
{
  return TBitField(1);
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
	return MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
	return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
	BitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
	BitField = s.BitField;
	MaxPower = s.MaxPower;
	return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
	if ((MaxPower != s.MaxPower) || (BitField != s.BitField))
	{
		return false;
	}
	return true;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
	if ((MaxPower != s.MaxPower) || (BitField != s.BitField))
	{
		return true;
	}
	return false;
}

TSet TSet::operator+(const TSet &s) // объединение
{
  return TSet(1);
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
	TSet tmp(MaxPower);
	tmp.BitField.SetBit(Elem);
	tmp.BitField.operator|(*this);
	return tmp;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
	TSet tmp(MaxPower);
	tmp.BitField.SetBit(Elem);
	tmp.BitField.operator|(*this);
	return tmp;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
    /*TSet tmp(max(s.MaxPower, MaxPower));
	tmp.BitField.operator&(s.BitField);
	tmp.MaxPower = max(s.MaxPower, MaxPower);
	return tmp;*/
	return TSet(1);
}

TSet TSet::operator~(void) // дополнение
{
	TSet tmp(MaxPower);
	tmp.BitField.operator~();
	return tmp;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
	return istr >> s.BitField;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
	return ostr << s.BitField;
}
