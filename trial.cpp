


if(
P1->Point_caculateDistance(P2)+P2->Point_caculateDistance(P3)>= P1->Point_caculateDistance(P3)
P1->Point_caculateDistance(P2)+P1->Point_caculateDistance(P3)>= P2->Point_caculateDistance(P3)
P3->Point_caculateDistance(P2)+P3->Point_caculateDistance(P1)>= P2->Point_caculateDistance(P1))
{
    return 1;
}
else
{
    return 0;
}
```
}
```