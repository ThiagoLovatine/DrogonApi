#pragma once
#include <drogon/HttpController.h>
using namespace drogon;
class TestController:public drogon::HttpController<TestController>
{
  public:
    METHOD_LIST_BEGIN
    METHOD_ADD(TestController::get,"/{2}",Get);

    METHOD_LIST_END
    void get(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback,int p1,std::string p2){
      Json::Value ret;
      ret["description"]="Teste da api usando DROGON/C++";
      ret["feature"]="Teste de retorno com JSON";
      ret["valor_inteiro"]=1123123;
      auto resp=HttpResponse::newHttpJsonResponse(ret);
      callback(resp);
    };
};
