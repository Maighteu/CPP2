#ifndef EVENT_H
#define EVENT_H

class Event
{
  private:
    int code;
    char *title;

  public:
    Event();
    ~Event();

    void setCode(int c);
    void setTitle(const char *t);

    int getCode()const;
    const char* getTitle() const;

    void display() const;
};

#endif
