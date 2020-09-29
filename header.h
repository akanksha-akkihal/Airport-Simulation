//A linked list node to store queue entry
struct plane{
int id;
struct plane *next;
};


void EndIns(struct plane ** head, int name);
void Frontdel(struct plane **head);
void end_delete(struct plane *head);
int getCount(struct plane* head);