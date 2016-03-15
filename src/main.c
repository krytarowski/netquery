/*
 Copyright (c) 2016 Kamil Rytarowski
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:

 1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
 BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include <err.h>

#include <c/GraphQLAstNode.h>
#include <c/GraphQLAstVisitor.h>
#include <c/GraphQLParser.h>

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

static struct GraphQLAstVisitorCallbacks callbacks;

static int
visit_document(const struct GraphQLAstDocument *document, void *user_data)
{
	printf("%s(): hello..\n", __func__);

	return 0;
}

static void
end_visit_document(const struct GraphQLAstDocument *document, void *user_data)
{
	printf("%s(): hello..\n", __func__);

	return;
}

int
main(int argc, char **argv)
{
	struct GraphQLAstNode *ast;
	const char *error;

	if (argc != 2)
		errx(EXIT_FAILURE, "No query");

	ast = graphql_parse_string(argv[1], &error);
	if (ast == NULL) {
		fprintf(stderr, "Error: %s\n", error);
		graphql_error_free(error);
		exit(EXIT_FAILURE);
	}

	callbacks.visit_document = visit_document;
	callbacks.end_visit_document = end_visit_document;

	graphql_node_visit(ast, &callbacks, NULL);

	graphql_node_free(ast);

	return EXIT_SUCCESS;
}
