#include <restclient-cpp/connection.h>
#include <restclient-cpp/restclient.h>
#include <served/served.hpp>

#include "./config/config.cpp"
#include "./tui/app.cpp"

int main(int argc, char const *argv[]) {
  /* Config *config = new Config(); */
  /* App *app = new App(); */

  served::multiplexer mux;

  mux.handle("/authenticate")
      .get([](served::response &res, const served::request &req) {
        std::string url = "https://ticktick.com/oauth/authorize";
        url += "?client_id=<secret>";
        url += "&scope=tasks:write%20tasks:read";
        url += "&state=state";
        url += "&redirect_uri=http://127.0.0.1:8080/redirect";
        url += "&response_type=code";

        res.set_status(301);
        res.set_header("Location", url);
      });

  mux.handle("/redirect")
      .get([](served::response &res, const served::request &req) {
        std::string grant_type = "authorization_code";
        std::string code = req.query.get("code");
        std::string redirect_uri = "http://127.0.0.1:8080/redirect";

        std::string body = "{\"grant_type\":\"" + grant_type + "\",\"code\":\"" + code +
                           "\",\"redirect_uri\":\"" + redirect_uri + "\"}";

				std:: string body2 = "grant_type=" + grant_type + "&code=" + code + "&redirect_uri=" + redirect_uri;

        std::cout << body << std::endl;

        try {
          RestClient::init();
          RestClient::Connection *conn =
              new RestClient::Connection("https://ticktick.com/oauth/token");

          conn->SetBasicAuth("<secret>",
                             "<secret>");

          RestClient::HeaderFields headers;
          headers["Content-Type"] = "application/x-www-form-urlencoded";
          conn->SetHeaders(headers);

          RestClient::Response r = conn->post("", body2);

          res << r.body;
        } catch (const std::exception &e) {
					res << e.what();
        }
      });

  served::net::server server("127.0.0.1", "8080", mux);
  server.run(1);

  return (EXIT_SUCCESS);
}
