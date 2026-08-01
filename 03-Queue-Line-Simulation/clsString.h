#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class clsString
{
private:
    string _Value;

public:

    // ---------------- Constructors ----------------

    clsString()
    {
        _Value = "";
    }

    clsString(string Value)
    {
        _Value = Value;
    }

    // ---------------- Properties ----------------

    void SetValue(string Value)
    {
        _Value = Value;
    }
    string GetValue()
    {
        return _Value;
    }
    __declspec(property(get = GetValue, put = SetValue)) string Value;

    // ---------------- Length & Word Counting ----------------

    static short Length(string S1)
    {
        return (short)S1.length();
    }

    short Length()
    {
        return (short)_Value.length();
    }

    static short CountWords(string S1)
    {
        string delim = " ";
        short counter = 0;
        size_t pos = 0; 

        while ((pos = S1.find(delim)) != string::npos)
        {
            string word = S1.substr(0, pos);
            if (word != "")
                counter++;

            S1.erase(0, pos + delim.length());
        }

        if (S1 != "")
            counter++; 

        return counter;
    }

    short CountWords()
    {
        return CountWords(_Value);
    }

    // ---------------- Case Conversion ----------------

    static string UpperFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;

        for (size_t i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
                S1[i] = toupper(S1[i]);

            isFirstLetter = (S1[i] == ' ');
        }

        return S1;
    }

    void UpperFirstLetterOfEachWord()
    {
        _Value = UpperFirstLetterOfEachWord(_Value);
    }

    static string LowerFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;

        for (size_t i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ' && isFirstLetter)
                S1[i] = tolower(S1[i]);

            isFirstLetter = (S1[i] == ' ');
        }

        return S1;
    }

    void LowerFirstLetterOfEachWord()
    {
        _Value = LowerFirstLetterOfEachWord(_Value);
    }

    static string UpperAllString(string S1)
    {
        for (size_t i = 0; i < S1.length(); i++)
            S1[i] = toupper(S1[i]);

        return S1;
    }

    void UpperAllString()
    {
        _Value = UpperAllString(_Value);
    }

    static string LowerAllString(string S1)
    {
        for (size_t i = 0; i < S1.length(); i++)
            S1[i] = tolower(S1[i]);

        return S1;
    }

    void LowerAllString()
    {
        _Value = LowerAllString(_Value);
    }

    static char InvertLetterCase(char Ch)
    {
        return isupper(Ch) ? tolower(Ch) : toupper(Ch);
    }

    static string InvertAllLettersCase(string S1)
    {
        for (size_t i = 0; i < S1.length(); i++)
            S1[i] = InvertLetterCase(S1[i]);

        return S1;
    }

    void InvertAllLettersCase()
    {
        _Value = InvertAllLettersCase(_Value);
    }

    // ---------------- Counting Letters ----------------

    enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

    static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
    {
        if (WhatToCount == enWhatToCount::All)
            return (short)S1.length();

        short counter = 0;

        for (size_t i = 0; i < S1.length(); i++)
        {
            if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
                counter++;

            if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
                counter++;
        }

        return counter;
    }

    static short CountCapitalLetters(string S1)
    {
        return CountLetters(S1, enWhatToCount::CapitalLetters);
    }

    short CountCapitalLetters()
    {
        return CountCapitalLetters(_Value);
    }

    static short CountSmallLetters(string S1)
    {
        return CountLetters(S1, enWhatToCount::SmallLetters);
    }

    short CountSmallLetters()
    {
        return CountSmallLetters(_Value);
    }

    static short CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
    {
        short counter = 0;

        for (size_t i = 0; i < S1.length(); i++)
        {
            if (MatchCase)
            {
                if (S1[i] == Letter)
                    counter++;
            }
            else
            {
                if (tolower(S1[i]) == tolower(Letter))
                    counter++;
            }
        }

        return counter;
    }

    short CountSpecificLetter(char Letter, bool MatchCase = true)
    {
        return CountSpecificLetter(_Value, Letter, MatchCase);
    }

    static bool IsVowel(char Ch)
    {
        Ch = tolower(Ch);
        return (Ch == 'a' || Ch == 'e' || Ch == 'i' || Ch == 'o' || Ch == 'u');
    }

    static short CountVowels(string S1)
    {
        short counter = 0;

        for (size_t i = 0; i < S1.length(); i++)
        {
            if (IsVowel(S1[i]))
                counter++;
        }

        return counter;
    }

    short CountVowels()
    {
        return CountVowels(_Value);
    }

    // ---------------- Split / Join ----------------

    static vector<string> Split(string S1, const string& Delim)
    {
        vector<string> vString;

        size_t pos;
        string sWord;

        while ((pos = S1.find(Delim)) != string::npos)
        {
            sWord = S1.substr(0, pos);
            vString.push_back(sWord);

            S1.erase(0, pos + Delim.length());
        }

        if (!S1.empty())
        {
            vString.push_back(S1);
        }

        return vString;
    }

    vector<string> Split(string Delim)
    {
        return Split(_Value, Delim);
    }

    static string JoinString(vector<string> vString, string Delim)
    {
        if (vString.empty())
            return "";

        string result = "";
        for (string& s : vString)
            result += s + Delim;

        return result.substr(0, result.length() - Delim.length());
    }

    static string JoinString(string arrString[], short Length, string Delim)
    {
        vector<string> vString(arrString, arrString + Length);
        return JoinString(vString, Delim);
    }

    // ---------------- Trimming ----------------

    static string TrimLeft(string S1)
    {
        for (size_t i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
                return S1.substr(i);
        }
        return "";
    }

    void TrimLeft()
    {
        _Value = TrimLeft(_Value);
    }

    static string TrimRight(string S1)
    {
        for (int i = (int)S1.length() - 1; i >= 0; i--)
        {
            if (S1[i] != ' ')
                return S1.substr(0, i + 1);
        }
        return "";
    }

    void TrimRight()
    {
        _Value = TrimRight(_Value);
    }

    static string Trim(string S1)
    {
        return TrimLeft(TrimRight(S1));
    }

    void Trim()
    {
        _Value = Trim(_Value);
    }

    // ---------------- Word Manipulation ----------------

    static string ReverseWordsInString(string S1)
    {
        vector<string> words = Split(S1, " ");

        if (words.empty())
            return "";

        string result = "";
        for (vector<string>::reverse_iterator it = words.rbegin(); it != words.rend(); ++it)
            result += *it + " ";

        return result.substr(0, result.length() - 1); 
    }

    void ReverseWordsInString()
    {
        _Value = ReverseWordsInString(_Value);
    }

    static string ReplaceWord(string S1, string StringToReplace, string ReplaceTo, bool MatchCase = true)
    {
        vector<string> words = Split(S1, " ");

        for (string& word : words)
        {
            if (MatchCase)
            {
                if (word == StringToReplace)
                    word = ReplaceTo;
            }
            else
            {
                if (LowerAllString(word) == LowerAllString(StringToReplace))
                    word = ReplaceTo;
            }
        }

        return JoinString(words, " ");
    }

    string ReplaceWord(string StringToReplace, string ReplaceTo)
    {
        return ReplaceWord(_Value, StringToReplace, ReplaceTo);
    }

    static string RemovePunctuations(string S1)
    {
        string result = "";

        for (size_t i = 0; i < S1.length(); i++)
        {
            if (!ispunct(S1[i]))
                result += S1[i];
        }

        return result;
    }

    void RemovePunctuations()
    {
        _Value = RemovePunctuations(_Value);
    }
};



