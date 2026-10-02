library(stringr)

DocumentParser <- setRefClass("DocumentParser",
    fields = list(
        text = "character",
        tokens = "character"
    ),
    methods = list(
        initialize = function(text) {
            .self$text <- text
            .self$tokens <- character(0)
            return(.self)
        },
        preprocess_text = function() {
            .self$text <- tolower(.self$text)
            .self$text <- str_replace_all(.self$text, "\\s+", " ")
            .self$text <- str_replace_all(.self$text, "[^\\w\\s]", "")
        },
        tokenize = function() {
            .self$tokens <- str_extract_all(.self$text, "\\b\\w+\\b")[[1]]
        }
    )
)

TokenAnalyzer <- setRefClass("TokenAnalyzer",
    fields = list(
        tokens = "character",
        frequency = "list"
    ),
    methods = list(
        initialize = function(tokens) {
            .self$tokens <- tokens
            .self$frequency <- list()
            return(.self)
        },
        analyze_frequency = function() {
            for (token in .self$tokens) {
                if (token %in% names(.self$frequency)) {
                    .self$frequency[[token]] <- .self$frequency[[token]] + 1
                } else {
                    .self$frequency[[token]] <- 1
                }
            }
        }
    )
)

main <- function() {
    text_data <- 'Example document text for parsing and tokenization. This is a simple example.'
    parser <- DocumentParser$new(text_data)
    parser$preprocess_text()
    parser$tokenize()
    analyzer <- TokenAnalyzer$new(parser$tokens)
    analyzer$analyze_frequency()
    for (token in names(analyzer$frequency)) {
        cat(token, ":", analyzer$frequency[[token]], "\n")
    }
}

main()