library(digest)

HashSimulator <- setRefClass("HashSimulator",
    fields = list(data = "character", hash_values = "list"),
    methods = list(
        initialize = function(data) {
            .self$data <- data
            .self$hash_values <- list()
        },
        generate_hashes = function() {
            for (i in seq_along(.self$data)) {
                key <- .self$data[i]
                hash_object <- digest(key, algo = "sha256")
                .self$hash_values[[key]] <- hash_object
            }
        },
        display_hashes = function() {
            for (key in names(.self$hash_values)) {
                value <- .self$hash_values[[key]]
                cat("Data:", key, ", Hash:", value, "\n")
            }
        }
    )
)

CipherSimulator <- setRefClass("CipherSimulator",
    fields = list(data = "character", cipher_text = "character"),
    methods = list(
        initialize = function(data) {
            .self$data <- data
            .self$cipher_text <- character()
        },
        encrypt = function() {
            for (char in .self$data) {
                encrypted_char <- intToUtf8((utf8ToInt(char) + 3) %% 256)
                .self$cipher_text <- c(.self$cipher_text, encrypted_char)
            }
        },
        display_cipher = function() {
            cat("Cipher Text:", paste(.self$cipher_text, collapse = ""), "\n")
        }
    )
)

main <- function() {
    data <- "HelloWorld"
    hash_simulator <- HashSimulator$new(data)
    cipher_simulator <- CipherSimulator$new(data)
    hash_simulator$generate_hashes()
    hash_simulator$display_hashes()
    cipher_simulator$encrypt()
    cipher_simulator$display_cipher()
    q(save = "no")
}

main()