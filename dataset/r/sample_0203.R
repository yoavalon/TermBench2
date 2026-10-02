r
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
        },
        tokenize = function() {
            .self$tokens <- str_extract_all(tolower(.self$text), "\\b\\w+\\b")[[1]]
        },
        filter_tokens = function(min_length) {
            .self$tokens <- .self$tokens[sapply(.self$tokens, nchar) > min_length]
        }
    )
)

TokenAnalyzer <- setRefClass("TokenAnalyzer",
    fields = list(
        tokens = "character",
        freq_dict = "list"
    ),
    methods = list(
        initialize = function(tokens) {
            .self$tokens <- tokens
            .self$freq_dict <- list()
        },
        calculate_frequencies = function() {
            for (token in .self$tokens) {
                if (token %in% names(.self$freq_dict)) {
                    .self$freq_dict[[token]] <- .self$freq_dict[[token]] + 1
                } else {
                    .self$freq_dict[[token]] <- 1
                }
            }
        },
        get_top_frequencies = function(n) {
            sorted_freq <- sort(.self$freq_dict, decreasing = TRUE)
            return(head(sorted_freq, n))
        }
    )
)

main <- function() {
    sample_text <- "This is a sample text for parsing and tokenization. Let's see how it works."
    parser <- new("DocumentParser", text = sample_text)
    parser$tokenize()
    parser$filter_tokens(3)
    analyzer <- new("TokenAnalyzer", tokens = parser$tokens)
    analyzer$calculate_frequencies()
    top_frequencies <- analyzer$get_top_frequencies(5)
    print(top_frequencies)
}

main()