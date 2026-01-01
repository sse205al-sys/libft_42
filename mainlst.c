#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	print_content(void *content)
{
	printf("[%s] -> ", (char *)content);
}

void	del_content(void *content)
{
	free(content);
}

void	*map_content(void *content)
{
	return (strdup((char *)content));
}

int	main(void)
{
	t_list	*head;
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;
	t_list	*n4;
	t_list	*new_list;

	head = NULL;
	printf("\n********* BONUS: LINKED LIST TEST *********\n");

	printf("\n--- Test: ft_lstnew & ft_lstadd_front ---\n");
	n1 = ft_lstnew(strdup("Node 1"));
	n2 = ft_lstnew(strdup("Node 2"));
	n3 = ft_lstnew(strdup("Node 3"));

	if (!n1 || !n2 || !n3)
	{
		printf("Malloc error in lstnew\n");
		return (1);
	}

	ft_lstadd_front(&head, n1);
	ft_lstadd_front(&head, n2);
	ft_lstadd_front(&head, n3);

	printf("List after add_front (Expected: 3->2->1):\n");
	ft_lstiter(head, print_content);
	printf("NULL\n");

	printf("\n--- Test: ft_lstsize & ft_lstlast ---\n");
	printf("Size: %d (Expected: 3)\n", ft_lstsize(head));
	if (head)
		printf("Last Node: %s\n", (char *)ft_lstlast(head)->content);

	printf("\n--- Test: ft_lstadd_back ---\n");
	n4 = ft_lstnew(strdup("Node 4 (Back)"));
	ft_lstadd_back(&head, n4);

	printf("List after add_back:\n");
	ft_lstiter(head, print_content);
	printf("NULL\n");

	printf("\n--- Test: ft_lstmap ---\n");
	new_list = ft_lstmap(head, map_content, del_content);
	printf("Mapped List (Copy):\n");
	ft_lstiter(new_list, print_content);
	printf("NULL\n");

	printf("\n--- Test: ft_lstclear ---\n");
	ft_lstclear(&head, del_content);
	ft_lstclear(&new_list, del_content);

	if (head == NULL && new_list == NULL)
		printf("Lists cleared successfully! (Head is NULL)\n");
	else
		printf("Error: Head is not NULL\n");

	printf("\n================ TESTS FINISHED ================\n");
	return (0);
}
