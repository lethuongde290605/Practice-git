#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

#define improveSpeed             \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);

using namespace std;

struct UM
{
    unordered_map<string, UM> um;
};

class MyCalendar
{
private:
    set<pair<int, bool>> ms;

public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        set<pair<int, bool>>::iterator it = ms.upper_bound({start, true});
        if (it == ms.end() || (*it).second == false)
        {
            return false;
        }
        ms.insert({start, 1});
        ms.insert({end - 1, 0});
        return true;
    }
};

class MyCalendarTwo
{
private:
    set<pair<int, int>> interval;
    set<pair<int, int>> triple;

public:
    MyCalendarTwo()
    {
    }

    bool book(int start, int end)
    {
        set<pair<int, int>>::iterator it = triple.upper_bound({start, end});
        if (it != triple.end() && it->second < end)
            return false;
        set<pair<int, int>>::iterator in = interval.upper_bound({start, end});
        if (in != interval.end() && in->second < end)
        {
            triple.insert(make_pair(in->second, end));
            interval.erase(in);
            interval.insert(make_pair(max(in->first, end), min(start, in->second)));
        }
        interval.insert(make_pair(end, start));
        return true;
    }
};

class MyCircularDeque
{
private:
    int *dequeue;
    int maxSize;
    int size = 0;
    int start = 0, end = 0;

public:
    MyCircularDeque(int k)
    {
        dequeue = new int[k];
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        if (start == end)
        {
            start = (start == 0) ? maxSize - 1 : start - 1;
            end = start;
        }
        else
            start = (start == 0) ? maxSize - 1 : start - 1;
        dequeue[start] = value;
        size++;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        if (start == end)
        {
            end = (end == maxSize - 1) ? 0 : end + 1;
            start = end;
        }
        else
            end = (end == maxSize - 1) ? 0 : end + 1;
        dequeue[end] = value;
        size++;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        size--;
        start = (start == maxSize - 1) ? 0 : start + 1;
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
        size--;
        end = (end == 0) ? maxSize - 1 : end - 1;
        return true;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return dequeue[start];
    }

    int getRear()
    {
        if (!isEmpty())
            return dequeue[end];
        return -1;
    }

    bool isEmpty()
    {
        if (size == 0)
            return true;
        return false;
    }

    bool isFull()
    {
        if (size == maxSize)
            return true;
        return false;
    }
};

vector<int> sumPrefixScores(vector<string> &words)
{
    int nWord = words.size();
    for (int i = 0; i < nWord; i++)
    {
        int size = words[i].size();
        int sum = 0;
        for (int j = 1; j <= size; j++)
        {
        }
    }
}

int main()
{
    improveSpeed;

    return 0;
}