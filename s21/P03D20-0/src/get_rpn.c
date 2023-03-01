char *get_rpn(struct token *lexeme) {
    int i = 0;

    while (lexeme) {
        if (lexeme->type == NUMBER) output_str[i] = lexeme.value;

        if (lexeme.type == FUNCTION) push(lexeme);

        if (lexeme.type == OPERATOR) {
            if ((peek(root))->value < lexeme->value)
                push(lexeme);
            else {  // ???
                while (peek(root)->value >= lexeme->value) {
                    // выталкиваем из стека в очередь
                }
                push(lexeme);
            }
        }

        if (lexeme.type == LEFT_PAREN) push(lexeme);

        if (lexeme.type == RIGHT_PAREN) {
            while (peek(root)->type != LEFT_PAREN) {
                pop(root);
            }
            // if (peek(root) == NULL) ;// пропущена скобка - неверное вырадение
            pop(root);

            if (peek(root)->value == FUNCTION) pop(root);
        }
    }

    // return ;
}