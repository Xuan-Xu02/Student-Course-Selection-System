#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include <cstring>  
using namespace std;


struct student {        //ѧ���ṹ
    string name;
    string num;
    string sex;
    string ke[6] = { "kong","kong","kong","kong","kong","kong" };
    int kyl = 0;
    string password = "123456";
    student* next;
};
student* head;

struct course {
    string name;
    string num;
    string cteacher;
    int sum = 0;
    course* next;
};
course* head1;
student* stu;
void help();
void zstudent();
void zteacher();
void meau();
int tpassword();
int spassword();
void glstudent();
void glcourse();
void addcourse();
void zengstudent();
void endstudent();
void delstudent();
void gstudent();
void glstudent();
void secstudent();
void sgpassword();
void xuanke();
void chaxun();
void seccour();
void gcourse();
void creat();

int main() {
    cout << "\t\t----------------------------------------\n"
        << "\t\t|             xx��ѧѡ��ϵͳ           |\n"
        << "\t\t|            ���롰Y����ʼ             |\n"
        << "\t\t|            ���롰N���˳�             |\n"
        << "\t\t----------------------------------------\n";
    cout << "\t\t������:";
    char A;
    cin >> A;
    if (A == 'Y') {
        creat();
        meau();
    }
    else if (A == 'N') {
        system("cls");
        cout << "\t\t             ��лʹ�ã��ټ���";
        exit(0);
    }
}
void meau() {
T:
    system("cls");
    cout << "\t\t----------------------------------------\n"
        << "\t\t|           ��ӭʹ��ѡ��ϵͳ          |\n"
        << "\t\t|             1.��ʦϵͳ              |\n"
        << "\t\t|             2.ѧ��ϵͳ              |\n"
        << "\t\t|               3.����                |\n"
        << "\t\t|               4.�˳�                |\n"
        << "\t\t----------------------------------------\n";
    cout << "\t\t\t   ��ѡ��";
    string A;
    cin >> A;
    if (A == "1") {
        zteacher();
    }
    else if (A == "2") {
        zstudent();
    }
    else if (A == "3") {
        help();
    }
    else if (A == "4") { cout << "\t\t       ллʹ�ã��ټ���"; exit(0); }
    else { cout << "\t\t           ���������������������ѡ��"; string a; cin >> a; goto T; }
}
void help() {
    system("cls");
    cout << "\tϵͳ�ɼ���������ƣ�������޸ĵ���ֻ������λ����\n"
        << "\t��ʦ����ͳһΪ111111��ѧ����ʼ���붼Ϊ123456\n"
        << "\tѧ���˺Ų����Լ��޸���Ҫ�ɽ�ʦ�޸�" << endl
        << "\t��ʦ���˺�ֻ��Ҫ��½����\n";
    cout << "\t����������������˵�";
    string A; cin >> A; meau();
}
void creat() {
    course* p, * s;
    head1 = new course;
    p = new course;
    s = new course;
    p = head1;
    p->num = "01";
    p->name = "�ߵ���ѧ";
    p->cteacher = "Xuan";
    p->sum = 121;
    p->next = NULL;
}

void zstudent() {
    int mi;
    mi = spassword();
    if (mi == 1) {
    s1:
        system("cls");
        cout << "\t\t---------------------------------\n"
            << "\t\t|            ѧ��ϵͳ            |\n"
            << "\t\t|           1.ѧ��ѡ��           |\n"
            << "\t\t|           2.��ѯ���           |\n"
            << "\t\t|           3.�޸�����           |\n"
            << "\t\t|           4.�����ϼ�           |\n"
            << "\t\t---------------------------------\n";
        string a;
        cin >> a;
        if (a == "1") {
            xuanke();
        }
        else if (a == "2") {
            chaxun();
        }
        else if (a == "3") {
            sgpassword();
        }
        else if (a == "4") {
            meau();
        }
        else {
            goto s1;
        }
    }

}
void xuanke() {
A:
    int f = 0, f1 = 0, f3 = 0;
    student* p, * s, * q;
    course* p1, * q1, * s1;
    p = new student; s = new student; q = new student;
    p1 = new course; s1 = new course; q1 = new course;
    system("cls");
    if (stu->kyl == 6) {
        cout << "\t\t\t      ��ѡ��γ����Ѵ����ޣ�";
        cout << "\n\t\t\t        ����س�����ѧ���˵�";
        getchar(); getchar();
        zstudent();
    }
    system("cls");
    int sum = stu->kyl;
    string k;
    cout << "\n\t\t\t                        �γ̵�";
    for (p1 = head1; p1; p1 = p1->next) {
        cout << "\n\t\t          �γ���:" << p1->name << " �γ̺�:" << p1->num << " ���ν�ʦ:" << p1->cteacher << " ������:" << p1->sum;
    }
    int ji = 0;
    cout << "\n\t\t\t      �㻹����ѡ��" << 6 - stu->kyl << "�ڿγ�.";
    cout << "\n\t\t\t       ������Ҫѡ��Ŀγ̺ţ�";
    cin >> k;
    for (p1 = head1; p1; p1 = p1->next) {
        if (p1->num == k) {
            f = 1; s1 = p1;
        }
        if (s1->sum > 0) {
            f1 = 1;
        }
        for (int i = 0; i < 6; i++) {
            if (k == stu->ke[i]) {
                f3 = 1;
            }
        }
    }
    if (f == 1 && f1 == 1 && f3 == 0) {
        stu->ke[sum] = k;
        stu->kyl++; s1->sum--; sum++;
        cout << "\n\t\t\t        �ɹ�ѡ��" << s1->name << "���ſγ̣�";
        cout << "\n\t\t\t        ����ѡ������Y,����ѧ���˵�����N:";
        char a; cin >> a;
        if (a == 'Y') { goto A; }
        else if (a == 'N') { zstudent(); }
    }
    else if (f == 1 && f1 == 0 && f3 == 0) {
        cout << "\n\t\t\t         �γ̿��������㣡������ѡ�������ϵ��ʦ���ӣ�"
            << "\n\t\t\t                 ����ѡ������Y,����ѧ���˵�����N";
        char b; cin >> b;
        if (b == 'Y') { goto A; }
        else if (b == 'N') { zstudent(); }
    }
    else if (f == 0) {
        cout << "\n\t\t\t            �γ̲����ڣ�������ѡ�������ϵ��ʦ��"
            << "\n\t\t\t                 ����ѡ������Y,����ѧ���˵�����N";
        char c; cin >> c;
        if (c == 'Y') { goto A; }
        else if (c == 'N') { zstudent(); }
    }
    else if (f3 == 1) {
        cout << "\n\t\t\t          ��ѡ�ÿγ�,������ѡ��\n\t\t\t            �س�����";
        getchar(); getchar();
        goto A;
    }
}
void chaxun() {
    course* p;
    p = new course;
    cout << "\t\t     ѡ�ν����";
    for (int i = 0; i < stu->kyl; i++) {
        for (p = head1; p; p = p->next) {
            if (stu->ke[i] == p->num)
                cout << "�γ���:" << p->name << " �����:" << p->num << " ���ν�ʦ:" << p->cteacher << " ������:" << p->sum << endl;
        }
    }
n:
    cout << "\t\t     �����ϼ�����Y";
    cout << "\t\t         ������:";
    char a; cin >> a;
    if (a == 'Y') { zstudent(); }
    else goto n;
}
void sgpassword() {
    system("cls");
    int k = 3, m = 2, p = 3, l = 2;
    string n, B;
    while (1) {
        cout << "\n\t\t\t      �����뵱ǰ�˺�,���δ�����˳���¼";
        cin >> n;
        if (stu->num == n) {
            system("cls");
            while (1) {
                cout << "\t\t\t              ���������룺\n";
                cout << "\t\t\t        ���������������ν��˳���¼��\n";
                cin >> B;
                if (stu->password == B) {
                    cout << "\n\t\t\t          ���ȷ�ϣ�������������:";
                    string A; cin >> A; stu->password = A;
                    cout << "\n\t\t\t       �޸���ɣ��س�����ѧ���˵�";
                    getchar(); getchar();
                    zstudent();
                }
                else {
                    k--; m--;
                    cerr << "\n\t\t\t��������������������룡�㻹��" << m + 1 << "�λ���\n" << endl;
                }
                if (k == 0) { help(); }
            }
        }
        else {
            p--; l--;
            cerr << "\n\t\t\t      �˺Ŵ������������룡�㻹��" << l + 1 << "�λ���\n" << endl;
        }
        if (p == 0) { help(); }
    }

}

void zteacher() {
    int mi;
    mi = tpassword();
    if (mi == 1) {
    t:
        system("cls");
        cout << "\t\t\t----------------------------------------------\n";
        cout << "\t\t\t|                   ��ʦ��                  |\n";
        cout << "\t\t\t|                 1.ѧ������                |\n";
        cout << "\t\t\t|                 2.�γ̹���                |\n";
        cout << "\t\t\t|                 3.�����ϼ�                |\n";
        cout << "\t\t\t----------------------------------------------\n";
        cout << "\t\t\t��ѡ��";
        char a; cin >> a;
        if (a == '1') {
            glstudent();
        }
        else if (a == '2') {
            glcourse();
        }
        else if (a == '3') {
            meau();
        }
        else { goto t; }
    }
} //��ʦϵͳ
void glcourse() {
s1:
    system("cls");
    cout << "\t\t---------------------------------\n"
        << "\t\t|          �γ̹���ϵͳ        |\n"
        << "\t\t|          1.��ѯ�γ�          |\n"
        << "\t\t|          2.�޸Ŀγ�          |\n"
        << "\t\t|          3.��ӿγ�          |\n"
        << "\t\t|         4.���ؽ�ʦ�˵�       |\n"
        << "\t\t---------------------------------\n";
    cout << "\t\t            ��ѡ��:";
    char x; cin >> x;
    if (x == '1') {
        seccour();
    }
    else if (x == '2') {
        gcourse();
    }
    else if (x == '4') {
        zteacher();
    }
    else if (x == '3') {
        addcourse();
    }
    else goto s1;
} //�γ̹���˵�
void gcourse() {
A:
    system("cls");
    int f = 0;
    cout << "\t\t          ������Ҫ�޸ĵĿγ����:";
    string x; cin >> x;
    for (course* i = head1; i->next; i = i->next) {
        if (x == i->num) {
            f = 1;
            cout << "\t\t       �밴�γ������γ̺š����ν�ʦ����������˳�������µĿγ���Ϣ\n";
            string a; cin >> a; i->name = a;
            cin >> i->num; cin >> i->cteacher; cin >> i->sum;
            cout << "\t\t" << x << "�γ����޸�\n\t\t�޸Ľ��:";
            cout << "�γ���:" << i->name << " �γ̺�:" << i->num << " ���ν�ʦ:" << i->cteacher << " ������:" << i->sum << endl;
            cout << "\n\t\t�����޸�����Y�����ؿγ̹���˵�����N";
        n:
            cout << "\t\t         ������:";
            char b; cin >> b;
            if (b == 'Y') { goto A; }
            else if (b == 'N') { glcourse(); }
            else goto n;
        }
    }
    if (f == 0) { cout << "\t\t      �γ̲����ڣ�����������󷵻ؿγ̹���:"; getchar(); }
} //�޸Ŀγ���Ϣ
void seccour() {
A:
    course* i;
    i = new course;

    system("cls");
    string s; int f = 0;
    cout << "\t\t         1.ͨ������Ų�ѯ\n"
        << "\t\t        2.���ؿγ̹���˵�\n"
        << "\t\t               ��ѡ��:";
    char x; cin >> x;
    if (x == '1') {
        cout << "\n\t\t         ��������:";
        cin >> s;
        for (i = head1; i != NULL; i = i->next) {
            if (s == i->num) {
                f = 1;
                cout << "\n\t\t\t      �ҵ��ÿγ̣�\n"; f = 1;
                cout << "�γ���:" << i->name << " �γ̺�:" << i->num << " ���ν�ʦ:" << i->cteacher << " ������:" << i->sum;
            n:
                cout << "\n\t\t      ������ѯ����Y�����ؿγ̹�������N";
                cout << "\t\t              ������:";
                char a; cin >> a;
                if (a == 'Y') { goto A; }
                else if (a == 'N') { glcourse(); }
                else goto n;
            }
        }
        if (f == 0) cout << "\t\t         �γ̲����ڣ�������������أ�"; getchar(); goto A;
    }
    else if (x == '2') { glcourse(); }
    else goto A;
}
void addcourse() {
A:
    system("cls");
    course* p, * s;
    p = head1; s = new course;
    while (p->next) {
        p = p->next;
    }
    cout << "\n\t\t ��ӿγ�\n";
    string n;
    cout << "�γ̺�:";
    cin >> n;
    s->num = n;
    cout << " �γ���:";
    cin >> n;
    s->name = n;
    cout << " ���ν�ʦ:";
    cin >> n;
    s->cteacher = n;
    cout << " ������:";
    int x;
    cin >> x;
    s->sum = x;
    p->next = s;
    s->next = NULL;
n:
    cout << "\n\t\t  �����������Y,��������N:";
    char f; cin >> f;
    if (f == 'Y')
    {
        goto A;
    }
    else if (f == 'N') {
        glcourse();
    }
    else goto n;
}

void glstudent() {
s1:
    system("cls");
    cout << "\t\t\t--------------------------------------------\n";
    cout << "\t\t\t|              ѧ������ϵͳ                |\n";
    cout << "\t\t\t|               1.����ѧ��                 |\n";
    cout << "\t\t\t|               2.ɾ��ѧ��                 |\n";
    cout << "\t\t\t|               3.�޸�ѧ��                 |\n";
    cout << "\t\t\t|               4.��ѯѧ��                 |\n";
    cout << "\t\t\t|               5.�����ϼ�                 |\n";
    cout << "\t\t\t--------------------------------------------\n";
    cout << "\t\t\t                ��ѡ�������";
    char a; cin >> a;
    if (a == '1') {
        zengstudent();

    }
    else if (a == '2') {
        delstudent();

    }
    else if (a == '3') {
        gstudent();
    }
    else if (a == '4') {
        secstudent();

    }
    else if (a == '5') {
        zteacher();
    }
    else {
        goto s1;
    }
}
void zengstudent() {
A:
    system("cls");
    int n;
    cout << "\t\t       ���������ѧ����:";
    cin >> n; cout << endl;

    head = new student;
    head->next = NULL;
    for (int i = 0; i < n; i++) {
        endstudent();
    }
B:
    cout << "\n\t\t        ����������롰Y��������ѧ������˵����롰N��\n"
        << "\t\t               ��ѡ��";
    char q; cin >> q;
    if (q == 'Y') { goto A; }
    else if (q == 'N') { glstudent(); }
    else { goto B; }
}
void endstudent() {
    student* p, * s;
    p = head;
    s = new student;
    while (p->next) {
        p = p->next;
    }
    string n;
    cout << "ѧ��:";
    cin >> n;
    s->num = n;
    cout << " ����:";
    cin >> n;
    s->name = n;
    cout << " �Ա�:";
    cin >> n;
    s->sex = n;
    p->next = s;
    s->next = NULL;
}
void delstudent() {
A:
    system("cls");
    string x; int f = 0;
    student* p, * s, * q;
    p = head;
    if (head == NULL) { cout << "\t\t   ��ѧ����Ϣ�����������ַ����أ�"; char b; cin >> b; glstudent(); }
    else {
        cout << "\t\t-------------------------------\n"
            << "\t\t|           ɾ��ѧ��          |\n"
            << "\t\t|        1.ͨ��ѧ�Ų���       |\n"
            << "\t\t|       2.����ѧ������˵�    |\n"
            << "\t\t-------------------------------\n";
        cout << "\t\t            ��ѡ��";
        char a;
        cin >> a;
        if (a == '1') {
            system("cls");
            cout << "\n\t\t         ������ɾ��ѧ��ѧ��:";
            cin >> x;
            while (p != NULL) {
                q = p; s = p->next;
                if (s->num == x) {
                    q->next = s->next;
                    free(s);
                n:
                    cout << "\n\t\t  ��ɾ��������ɾ������Y,��������N";
                    char c; cin >> c;
                    if (c == 'Y')goto A;
                    else if (c == 'N') { glstudent(); }
                    else goto n;
                }
                p = p->next;
            }
            cout << "\n\t\t ѧ�������ڣ�������������أ�"; getchar();
        }
        else if (a == '2') { glstudent(); }
        else goto A;
    }
}
void gstudent() {
A:
    student* p;
    p = head->next;
    system("cls");
    string name; int f = 0;
    cout << "\t\t----------------------------\n"
        << "\t\t|         �޸�ѧ��         |\n"
        << "\t\t|      1.ͨ��ѧ�Ų�ѯ      |\n"
        << "\t\t|     2.����ѧ������˵�   |\n"
        << "\t\t----------------------------\n"
        << "\t\t          ��ѡ��: ";
    char x; cin >> x;
    if (x == '1') {
        system("cls");
        cout << "\n\t\t       ������ѧ��:";
        cin >> name;
        while (p && p->num != name) {
            p = p->next;
        }
        if (p == NULL) { cout << "\n\t\t   ѧ��������!���������ַ�����:"; getchar(); goto A; }
        else {
            cout << "\n\t\t  ������ѧ����Ϣ:";
            cout << "\n����:"; cin >> p->name; cout << " ѧ��:"; cin >> p->num; cout << " �Ա�:"; cin >> p->sex; cout << endl;

        }
    n:
        cout << "\n\t\t  �����޸�����Y,��������N:"; char a; cin >> a;
        if (a == 'Y')goto A;
        else if (a == 'N') { glstudent(); }
        else goto n;
    }
    else if (x == '2') { glstudent(); }
    else goto A;
}
void secstudent() {
A:
    system("cls");
    string name;
    student* p;
    p = new student;
    course* q;
    q = new course;
    p = head;
    if (!p) {
        cout << "\t\t    ��ѧ����Ϣ,�������ѧ��,���������ַ�����:";
        getchar();
        return;
    }

    cout << "\t\t----------------------------\n"
        << "\t\t|        ��ѯѧ��           |\n"
        << "\t\t|      1.ͨ��ѧ�Ų�ѯ       |\n"
        << "\t\t|     2.����ѧ������˵�    |\n"
        << "\t\t----------------------------\n";
    cout << "\t\t          ��ѡ��:";
    char a;
    cin >> a;
    if (a == '1') {
        system("cls");
        cout << "\n\t\t       ������ѧ��:";
        cin >> name;
        while (p && p->num != name) {
            p = p->next;
        }
        if (!p) {
            cout << "\n\t\t   ѧ��������!���������ַ�����:";
            getchar();
            goto A;
        }

        cout << "\n����:" << p->name << " ѧ��:" << p->num << " �Ա�:" << p->sex << endl;
        cout << "\n\t\t   ��ѧ��ѡ�ν��\n";
        for (int i = 0; i < p->kyl; i++) {
            for (q = head1; q != NULL; q = q->next) {
                if (p->ke[i] == q->num) {
                    cout << "�γ���:" << q->name << " �γ̺�:" << q->num << " ���ν�ʦ:" << q->cteacher << " ������:"
                        << q->sum
                        << endl;
                }
            }
        }

    n:
        cout << "\n\t\t  ������ѯ����Y,��������N:";
        char b;
        cin >> b;
        if (b == 'Y') { goto A; }
        else if (b == 'N') { glstudent(); }
        else goto n;
    }
    else if (a == '2') { glstudent(); }
    else goto A;

}

int spassword() {
    system("cls");
    student* q, * p;
    q = new student;
    p = new student;
    p = head;
    if (p == NULL) {
        cout << "\t\t\t    û���κ�ѧ����Ϣ��������ϵ��ʦ��ӣ�";
        cout << "\n\t\t\t         ���������ַ������ϼ��˵�:";
        char a;
        cin >> a;
        if (a) { meau(); }
    }
    int k = 3, m = 2;
    char a; string n, A;
    cout << "\n\t\t\t           ������ѧ�ţ�";
    cin >> n; int j = 0;
    for (q = head; q; q = q->next) {
        if (n == q->num) {
            stu = q;
            cout << "��¼�ߣ�" << stu->name; goto m;
        }
    }
m:
    while (1) {
        cout << "\t\t\t        ���������룺\n";
        cout << "\t\t\t    ���������������ν��Զ��˳�\n";
        cin >> A;
        if (A == stu->password)return 1;
        else {
            k--; m--;
            cerr << "\n\t\t\t��������������������룡�㻹��" << m + 1 << "�λ���\n" << endl;
        }
        if (k == 0) { return 0; };
    }
}

int tpassword() {
    system("cls");
    int k = 3, m = 2, s = 7;
    string A = "111111", B;
    while (1) {
        cout << "\t\t\t        �������ʦ�������룺\n";
        cout << "\t\t\t    ���������������ν��Զ��˳�\n";
        int i = 0;
        cin >> B;
        if (A == B)return 1;
        else {
            k--; m--;
            cerr << "\n\t\t\t��������������������룡�㻹��" << m + 1 << "�λ���\n" << endl;
        }
        if (k == 0) { return 0; };
    }
}
