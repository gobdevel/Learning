#define HTTPSERVER_IMPL
#include "httpserver.h"

#define OK_RESPONSE     "OK\r\n"
#define MAX_BUFFER_SIZE 2048
#define MAX_SPACES      2
#define GREETING        "Hello Kubernetes (v2) "

// Global buffer
char     g_buffer[MAX_BUFFER_SIZE];
int      g_buffer_update_loc = 0;
uint32_t g_hit_count         = 0;

int request_target_is(struct http_request_s* request, char const* target) {
    http_string_t url = http_request_target(request);
    int           len = strlen(target);
    return len == url.len && memcmp(url.buf, target, url.len) == 0;
}

void handle_request(struct http_request_s* request) {
    struct http_response_s* response = http_response_init();
    http_response_status(response, 200);
    http_response_header(response, "Content-Type", "text/plain");

    if (request_target_is(request, "/healthz")) {
        // http_string_t body = http_request_body(request);
        http_response_header(response, "Content-Type", "text/plain");
        http_response_body(response, OK_RESPONSE, strlen(OK_RESPONSE));
    } else {
        g_hit_count += 1;
        sprintf(g_buffer + g_buffer_update_loc, "%u \r\n", g_hit_count);
        http_response_body(response, g_buffer, strlen(g_buffer));
    }
    http_respond(request, response);
}

int main() {
    // Update Greeting
    memset(g_buffer, 0, MAX_BUFFER_SIZE);
    memcpy(g_buffer, GREETING, strlen(GREETING));
    g_buffer_update_loc = strlen(GREETING);

    // Update hostname
    gethostname(g_buffer + g_buffer_update_loc, MAX_BUFFER_SIZE);
    g_buffer_update_loc = strlen(g_buffer);

    // Add spaces
    memset(g_buffer + g_buffer_update_loc, ' ', MAX_SPACES);
    g_buffer_update_loc += MAX_SPACES;

    memcpy(g_buffer + g_buffer_update_loc, ": ", 2);
    g_buffer_update_loc += 2;

    struct http_server_s* server = http_server_init(8080, handle_request);
    http_server_listen(server);
}
