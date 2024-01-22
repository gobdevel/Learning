CREATE DATABASE portfolio;
CREATE USER portfolio_admin WITH ENCRYPTED PASSWORD 'admin@tekyonix';
REVOKE CONNECT ON DATABASE portfolio FROM PUBLIC;
GRANT CONNECT ON DATABASE portfolio TO portfolio_admin;
GRANT ALL PRIVILEGES ON DATABASE portfolio to portfolio_admin;
\c portfolio admin
GRANT ALL ON SCHEMA public TO portfolio_admin;

\c postgres admin


CREATE DATABASE wikijs;
CREATE USER wikijs_admin WITH ENCRYPTED PASSWORD 'admin@tekyonix';
REVOKE CONNECT ON DATABASE wikijs FROM PUBLIC;
GRANT CONNECT ON DATABASE wikijs TO wikijs_admin;
GRANT ALL PRIVILEGES ON DATABASE wikijs to wikijs_admin;
\c wikijs admin
GRANT ALL ON SCHEMA public TO wikijs_admin;

