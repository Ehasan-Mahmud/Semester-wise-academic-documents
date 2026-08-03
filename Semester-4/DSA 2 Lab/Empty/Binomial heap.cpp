#include<bits/stdc++.h>
using namespace std;
class N
{
public:
    int k;
    int d;
    N*p;
    N*c;
    N*s;

    N(int x):k(x),d(0),p(NULL),c(NULL),s(NULL) {}
};

class BH
{
private:
    N*h;

    static N*m(N*a,N*b)
    {
        N*t=new N(0);
        N*y=t;

        while(a!=NULL&&b!=NULL)
        {
            if(a->d<=b->d)
            {
                y->s=a;
                a=a->s;
            }
            else
            {
                y->s=b;
                b=b->s;
            }
            y=y->s;
        }

        y->s=(a!=NULL)?a:b;
        N*r=t->s;
        delete t;
        return r;
    }

    void l(N*p,N*c)
    {
        c->p=p;
        c->s=p->c;
        p->c=c;
        p->d++;
    }

    void c()
    {
        if(h==NULL)return;

        N*pr=NULL;
        N*cu=h;
        N*ne=cu->s;

        while(ne!=NULL)
        {
            if(cu->d!=ne->d||(ne->s!=NULL&&ne->s->d==cu->d))
            {
                pr=cu;
                cu=ne;
            }
            else
            {
                if(cu->k<=ne->k)
                {
                    cu->s=ne->s;
                    l(cu,ne);
                }
                else
                {
                    if(pr==NULL)
                    {
                        h=ne;
                    }
                    else
                    {
                        pr->s=ne;
                    }
                    l(ne,cu);
                    cu=ne;
                }
            }
            ne=cu->s;
        }
    }

public:
    BH():h(NULL) {}

    ~BH()
    {
        while(h!=NULL)
        {
            e();
        }
    }

    void i(int x)
    {
        BH t;
        t.h=new N(x);
        u(t);
    }

    void u(BH&t)
    {
        N*r=m(h,t.h);
        h=r;
        t.h=NULL;

        c();
    }

    int e()
    {
        if(h==NULL)
        {
            throw runtime_error("Empty");
        }

        N*mn=h;
        N*pm=NULL;
        N*cu=h;
        N*pr=NULL;

        while(cu!=NULL)
        {
            if(cu->k<mn->k)
            {
                mn=cu;
                pm=pr;
            }
            pr=cu;
            cu=cu->s;
        }

        if(pm!=NULL)
        {
            pm->s=mn->s;
        }
        else
        {
            h=mn->s;
        }

        BH ch;
        N*chd=mn->c;
        N*pch=NULL;
        while(chd!=NULL)
        {
            N*nch=chd->s;
            chd->s=pch;
            chd->p=NULL;
            pch=chd;
            chd=nch;
        }
        ch.h=pch;

        u(ch);

        int mk=mn->k;
        delete mn;
        return mk;
    }
};

int main()
{
    BH bh;
    int a[]= {10,20,5,15,30};
    for(int x:a)
    {
        bh.i(x);
    }

    cout<<"Extracted Minimum Key: "<<bh.e()<<endl;

    return 0;
}
