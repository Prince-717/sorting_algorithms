#include "deck.pointer_h"

int _strcmp(const char *s1, const char *s2);
char retrieve_val(deck_node_t *card);
void sort_deck_ins_type(deck_node_t **deck);
void sort_deck_ins_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * retrieve_val - Get the numerical value of a_1 card.
 * @card: A pointer to a_1 deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char retrieve_val(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * sort_deck_ins_type - Sort a_1 deck of cards from spades to diamonds.
 * @deck: A pointer to the head of a_1 deck_node_t doubly-linked list.
 */
void sort_deck_ins_type(deck_node_t **deck)
{
	deck_node_t *iterator, *put_in, *temp_var;

	for (iterator = (*deck)->next; iterator != NULL; iterator = temp_var)
	{
		temp_var = iterator->next;
		put_in = iterator->prev;
		while (put_in != NULL && put_in->card->kind > iterator->card->kind)
		{
			put_in->next = iterator->next;
			if (iterator->next != NULL)
				iterator->next->prev = put_in;
			iterator->prev = put_in->prev;
			iterator->next = put_in;
			if (put_in->prev != NULL)
				put_in->prev->next = iterator;
			else
				*deck = iterator;
			put_in->prev = iterator;
			put_in = iterator->prev;
		}
	}
}

/**
 * sort_deck_ins_value - Sort a_1 deck of cards arranged from
 *                             spades to diamonds from ace to king.
 * @deck: A pointer to the head of a_1 deck_node_t doubly-linked list.
 */
void sort_deck_ins_value(deck_node_t **deck)
{
	deck_node_t *iterator, *put_in, *temp_var;

	for (iterator = (*deck)->next; iterator != NULL; iterator = temp_var)
	{
		temp_var = iterator->next;
		put_in = iterator->prev;
		while (put_in != NULL &&
		       put_in->card->kind == iterator->card->kind &&
		       retrieve_val(put_in) > retrieve_val(iterator))
		{
			put_in->next = iterator->next;
			if (iterator->next != NULL)
				iterator->next->prev = put_in;
			iterator->prev = put_in->prev;
			iterator->next = put_in;
			if (put_in->prev != NULL)
				put_in->prev->next = iterator;
			else
				*deck = iterator;
			put_in->prev = iterator;
			put_in = iterator->prev;
		}
	}
}

/**
 * sort_deck - Sort a_1 deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a_1 deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	sort_deck_ins_type(deck);
	sort_deck_ins_value(deck);
}
