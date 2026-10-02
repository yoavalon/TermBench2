r
parse_document <- function(text) {
    tokens <- c()
    buffer <- ""
    for (char in strsplit(text, NULL)[[1]]) {
        if (grepl("[[:alnum:]]|\\.", char) > 0) {
            buffer <- paste0(buffer, char)
        } else {
            if (nchar(buffer) > 0) {
                tokens <- c(tokens, buffer)
                buffer <- ""
            }
            if (char != " ") {
                tokens <- c(tokens, char)
            }
        }
    }
    if (nchar(buffer) > 0) {
        tokens <- c(tokens, buffer)
    }
    return(tokens)
}

main <- function() {
    document <- "Example 1.23 and 4.567."
    tokens <- parse_document(document)
    print(tokens)
}

main()