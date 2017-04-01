var fs = require('fs');
fs.readFile("/home/farzicoder/EffiTesting/temp.json", 'utf8', function readFileCallback(err, data){
  if(err){
    console.log(err);
  }else{
    obj = JSON.parse(data);
    console.log(obj.table);
    obj.table.push({"filePath": "test.cpp", "type": "warning", "text": "text Analysis"});
    json = JSON.stringify(obj);
    fs.writeFile("/home/farzicoder/EffiTesting/temp.json", json, 'utf8', function(err){
      if (err){
        console.log(err);
      }
    })
  }
});
