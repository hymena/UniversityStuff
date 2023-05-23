struct nodeClass
{
	int classID;
	double classMidtermAverage;
	struct nodeClass *next;
	struct nodeStudent *studentPtr;
};

struct nodeStudent
{
	int studentID;
	int midterm;
	struct nodeStudent *next;
};

// You must write all the function definitions to be used in this lab into this file.
// You may also write other functions that may be called from our functions.
// Do not make any changes to the main.c file.
// Upload function.h file to the system as StudentNumber.h.

void insert(struct nodeClass **head, int id, int midterm)
{
	if (*head == NULL)
	{

		(*head) = (struct nodeClass *)malloc(sizeof(struct nodeClass)); //1st class
		(*head)->studentPtr = NULL;										//set students for 1st class  to null
		(*head)->classID = 1;
		(*head)->classMidtermAverage = 0;
		(*head)->next = (struct nodeClass *)malloc(sizeof(struct nodeClass)); //2nd class
		(*head)->next->studentPtr = NULL;
		(*head)->next->classID = 2;
		(*head)->next->classMidtermAverage = 0;
		(*head)->next->next = (struct nodeClass *)malloc(sizeof(struct nodeClass)); //3rd class
		(*head)->next->next->studentPtr = NULL;
		(*head)->next->next->classID = 3;
		(*head)->next->next->classMidtermAverage = 0;
		(*head)->next->next->next = (struct nodeClass *)malloc(sizeof(struct nodeClass)); //4th class
		(*head)->next->next->next->studentPtr = NULL;
		(*head)->next->next->next->classID = 4;
		(*head)->next->next->next->classMidtermAverage = 0;
		(*head)->next->next->next->next = NULL; //after 4th class set the next null

		if ((id < 67000) && (id > 66000))
		{
			(*head)->studentPtr = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
			(*head)->studentPtr->next = NULL;
			(*head)->studentPtr->studentID = id;
			(*head)->studentPtr->midterm = midterm;
		}

		if ((id < 78000) && (id > 77000))
		{
			(*head)->next->studentPtr = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
			(*head)->next->studentPtr->next = NULL;
			(*head)->next->studentPtr->studentID = id;
			(*head)->next->studentPtr->midterm = midterm;
		}
		if ((id < 89000) && (id > 88000))
		{
			(*head)->next->next->studentPtr = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
			(*head)->next->next->studentPtr->next = NULL;
			(*head)->next->next->studentPtr->studentID = id;
			(*head)->next->next->studentPtr->midterm = midterm;
		}
		if ((id < 100000) && (id > 99000))
		{
			(*head)->next->next->next->studentPtr = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
			(*head)->next->next->next->studentPtr->next = NULL;
			(*head)->next->next->next->studentPtr->studentID = id;
			(*head)->next->next->next->studentPtr->midterm = midterm;
		}
	}
	else
	{
		if ((id < 67000) && (id > 66000))
		{									 //Then we picked first class
			if ((*head)->studentPtr == NULL) //Check if any students are enroled
			{
				(*head)->studentPtr = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
				(*head)->studentPtr->next = NULL;
				(*head)->studentPtr->studentID = id;
				(*head)->studentPtr->midterm = midterm;
			}
			else if (midterm > (*head)->studentPtr->midterm)
			{
				struct nodeStudent *new = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
				new->studentID = id;
				new->midterm = midterm;
				new->next = (*head)->studentPtr;
				(*head)->studentPtr = new;
			}
			else if(midterm == (*head)->studentPtr->midterm && id < (*head)->studentPtr->studentID ){
				struct nodeStudent *new = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
				new->studentID = id;
				new->midterm = midterm;
				new->next = (*head)->studentPtr;
				(*head)->studentPtr = new;
			}
			else //If there is already enroled students travel along them
			{
				struct nodeStudent *tempSt = (*head)->studentPtr;
				while (tempSt->next != NULL)
				{
					if (midterm > tempSt->next->midterm) //Assign them decreasing order
					{
						struct nodeStudent *new = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
						new->studentID = id;
						new->midterm = midterm;
						new->next = tempSt->next;
						tempSt->next = new;
						return;
					}
					if(midterm == tempSt->next->midterm && id<tempSt->next->studentID){
						struct nodeStudent *new = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
						new->studentID = id;
						new->midterm = midterm;
						new->next = tempSt->next;
						tempSt->next = new;
						return;
					}
					tempSt = tempSt->next;
				}

				struct nodeStudent *new = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
				new->studentID = id;
				new->midterm = midterm;
				new->next = NULL;
				tempSt->next = new;
			}
		}
		else if ((id < 78000) && (id > 77000))
		{										   //Then we picked first class
			if ((*head)->next->studentPtr == NULL) //Check if any students are enroled
			{
				(*head)->next->studentPtr = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
				(*head)->next->studentPtr->next = NULL;
				(*head)->next->studentPtr->studentID = id;
				(*head)->next->studentPtr->midterm = midterm;
			}
			else if (midterm > (*head)->next->studentPtr->midterm)
			{
				struct nodeStudent *new = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
				new->studentID = id;
				new->midterm = midterm;
				new->next = (*head)->next->studentPtr;
				(*head)->next->studentPtr = new;
			}
			else if(midterm == (*head)->studentPtr->midterm && id < (*head)->studentPtr->studentID ){
				struct nodeStudent *new = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
				new->studentID = id;
				new->midterm = midterm;
				new->next = (*head)->studentPtr;
				(*head)->studentPtr = new;
			}
			else //If there is already enroled students travel along them
			{
				struct nodeStudent *tempSt = (*head)->next->studentPtr;
				while (tempSt->next != NULL)
				{
					if (midterm > tempSt->next->midterm) //Assign them decreasing order
					{
						struct nodeStudent *new = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
						new->studentID = id;
						new->midterm = midterm;
						new->next = tempSt->next;
						tempSt->next = new;
						return;
					}
					if(midterm == tempSt->next->midterm && id<tempSt->next->studentID){
						struct nodeStudent *new = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
						new->studentID = id;
						new->midterm = midterm;
						new->next = tempSt->next;
						tempSt->next = new;
						return;
					}
					tempSt = tempSt->next;
				}

				struct nodeStudent *new = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
				new->studentID = id;
				new->midterm = midterm;
				new->next = NULL;
				tempSt->next = new;
			}
		}
		else if ((id < 89000) && (id > 88000))
		{												 //Then we picked first class
			if ((*head)->next->next->studentPtr == NULL) //Check if any students are enroled
			{
				(*head)->next->next->studentPtr = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
				(*head)->next->next->studentPtr->next = NULL;
				(*head)->next->next->studentPtr->studentID = id;
				(*head)->next->next->studentPtr->midterm = midterm;
			}
			else if (midterm > (*head)->next->next->studentPtr->midterm)
			{
				struct nodeStudent *new = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
				new->studentID = id;
				new->midterm = midterm;
				new->next = (*head)->next->next->studentPtr;
				(*head)->next->next->studentPtr = new;
			}
			else if(midterm == (*head)->studentPtr->midterm && id < (*head)->studentPtr->studentID ){
				struct nodeStudent *new = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
				new->studentID = id;
				new->midterm = midterm;
				new->next = (*head)->studentPtr;
				(*head)->studentPtr = new;
			}
			else //If there is already enroled students travel along them
			{
				struct nodeStudent *tempSt = (*head)->next->next->studentPtr;
				while (tempSt->next != NULL)
				{
					if (midterm > tempSt->next->midterm) //Assign them decreasing order
					{
						struct nodeStudent *new = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
						new->studentID = id;
						new->midterm = midterm;
						new->next = tempSt->next;
						tempSt->next = new;
						return;
					}
					if(midterm == tempSt->next->midterm && id<tempSt->next->studentID){
						struct nodeStudent *new = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
						new->studentID = id;
						new->midterm = midterm;
						new->next = tempSt->next;
						tempSt->next = new;
						return;
					}
					tempSt = tempSt->next;
				}

				struct nodeStudent *new = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
				new->studentID = id;
				new->midterm = midterm;
				new->next = NULL;
				tempSt->next = new;
			}
		}
		else if ((id < 100000) && (id > 99000))
		{													   //Then we picked first class
			if ((*head)->next->next->next->studentPtr == NULL) //Check if any students are enroled
			{
				(*head)->next->next->next->studentPtr = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
				(*head)->next->next->next->studentPtr->next = NULL;
				(*head)->next->next->next->studentPtr->studentID = id;
				(*head)->next->next->next->studentPtr->midterm = midterm;
			}
			else if (midterm > (*head)->next->next->next->studentPtr->midterm)
			{
				struct nodeStudent *new = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
				new->studentID = id;
				new->midterm = midterm;
				new->next = (*head)->next->next->next->studentPtr;
				(*head)->next->next->next->studentPtr = new;
			}
			else if(midterm == (*head)->studentPtr->midterm && id < (*head)->studentPtr->studentID ){
				struct nodeStudent *new = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
				new->studentID = id;
				new->midterm = midterm;
				new->next = (*head)->studentPtr;
				(*head)->studentPtr = new;
			}
			else //If there is already enroled students travel along them
			{
				struct nodeStudent *tempSt = (*head)->next->next->next->studentPtr;
				while (tempSt->next != NULL)
				{
					if (midterm > tempSt->next->midterm) //Assign them decreasing order
					{
						struct nodeStudent *new = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
						new->studentID = id;
						new->midterm = midterm;
						new->next = tempSt->next;
						tempSt->next = new;
						return;
					}
					if(midterm == tempSt->next->midterm && id<tempSt->next->studentID){
						struct nodeStudent *new = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
						new->studentID = id;
						new->midterm = midterm;
						new->next = tempSt->next;
						tempSt->next = new;
						return;
					}
					tempSt = tempSt->next;
				}

				struct nodeStudent *new = (struct nodeStudent *)malloc(sizeof(struct nodeStudent));
				new->studentID = id;
				new->midterm = midterm;
				new->next = NULL;
				tempSt->next = new;
			}
		}
	}
}

void computeClassAverage(struct nodeClass *head)
{
	struct nodeClass *tempClass = head;
	while (tempClass != NULL)
	{
		struct nodeStudent *tempSt = tempClass->studentPtr;
		int stNumber = 0;
		float total = 0;
		while (tempSt != NULL)
		{
			total += tempSt->midterm;
			stNumber += 1;
			tempSt = tempSt->next;
		}
		tempClass->classMidtermAverage = total / stNumber;
		total = 0;
		stNumber = 0;
		tempClass = tempClass->next;
	}
}

void printAll(struct nodeClass *head)
{
	struct nodeClass *tempClass = head;
	while (tempClass != NULL)
	{
		printf("%d %.2f\n", tempClass->classID, tempClass->classMidtermAverage);
		struct nodeStudent *tempSt = tempClass->studentPtr;
		while (tempSt != NULL)
		{

			printf("%d %d\n", tempSt->studentID, tempSt->midterm);
			tempSt = tempSt->next;
		}
		tempClass = tempClass->next;
	}
}