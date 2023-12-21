using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;
using Newtonsoft.Json.Linq;
using System.Web.Mvc;
using System.Threading.Tasks;

using webAPI2.Models;
using Newtonsoft.Json;

namespace webAPI2.Controllers
{
    public class HomeController : ApiController
    {

        //GET: api
        [Microsoft.AspNetCore.Mvc.HttpGet]
        public IEnumerable<Traineeskill> Get()
        {
            using (RegisterationTraineeEntities dbContext = new RegisterationTraineeEntities())
            {
                dbContext.Configuration.ProxyCreationEnabled = false;
                return dbContext.Traineeskills.ToList();
            }
        }
    }
}