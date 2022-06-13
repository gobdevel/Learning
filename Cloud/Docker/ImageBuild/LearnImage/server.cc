#include <cstdlib>
#define HTTPSERVER_IMPL
#include "httpserver.h"

constexpr static const char OK_RESPOSE[] = "OK\r\n";
constexpr static const char GREETING[]   = "Echo-Server ";
#define OK_RESPONSE     "OK\r\n"
#define MAX_BUFFER_SIZE 2048
#define MAX_SPACES      2
#define GREETING        "Hello Kubernetes (v2) "

// Global buffer
char     g_buffer[MAX_BUFFER_SIZE];
int      g_buffer_update_loc = 0;
uint32_t g_hit_count         = 0;

constexpr static const std::size_t TARGET_MAX_SIZE = 12;
typedef enum { DEFAULT = 0, ENV, HEALTHZ, LAST } TARGETS;
constexpr const char Targets[LAST][TARGET_MAX_SIZE] = {"env", "healthz"};

int getTarget(struct http_request_s *request) {
    http_string_t url = http_request_target(request);
    if (url.len == 1) return DEFAULT;

    TARGETS tar = LAST;
    switch (url.buf[1]) {
        case 'e':
            tar = ENV;
            break;
        case 'h':
            tar = HEALTHZ;
            break;
        default:
            break;
    }
    return tar;
}

void handle_request(struct http_request_s *request) {
    struct http_response_s *response = http_response_init();
    http_response_status(response, 200);
    http_response_header(response, "Content-Type", "text/plain");

    switch (getTarget(request)) {
        case DEFAULT: {
            g_hit_count += 1;
            sprintf(g_buffer + g_buffer_update_loc, "%u \r\n", g_hit_count);
            http_response_body(response, g_buffer, strlen(g_buffer));
            break;
        }
        case ENV: {
            const char *env = std::getenv("BROKER_URL");
            sprintf(g_buffer + g_buffer_update_loc, "\r\n%s:%s \r\n",
                    "BROKER_URL", (env ? env : "Default"));
            http_response_body(response, g_buffer, strlen(g_buffer));
            break;
        }

        case HEALTHZ: {
            http_response_body(response, OK_RESPONSE, strlen(OK_RESPONSE));
            break;
        }
        default: {
            http_response_status(response, 401);
        }
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

    struct http_server_s *server = http_server_init(8080, handle_request);
    http_server_listen(server);
}
