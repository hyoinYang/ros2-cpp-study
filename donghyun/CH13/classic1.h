#ifndef CLASSIC1_H_
#define CLASSIC1_H_

class Cd
{
private:
    char *performers;
    char *label;
    int selections;
    double playtime;
public:
    Cd(const char* s1="no name", const char* s2="no label", int n=0, double x=0.0);
    Cd(const Cd& d);
	virtual ~Cd();
    virtual void Report() const;
    Cd& operator=(const Cd& d);
};

class Classic : public Cd
{
private:
    char *title;
public:
    Classic(const char* s3="no title", const char* s1="no name",
            const char* s2="no label", int n=0, double x=0.0);
	Classic(const Classic& d);
    Classic(const Cd& d, const char* s3);
    ~Classic();
    Classic& operator=(const Classic& d);
    virtual void Report() const;
};

#endif
