from full2 import *
from fastapi import FastAPI
from pydantic import BaseModel

class Item(BaseModel):
    text:str


app = FastAPI()
@app.post("/api/")
async def create_item(item: Item):
    token_count = estimate_tokens(system_message)
    max_response_tokens = 500
    token_count = estimate_tokens(new_message)
    user_message = item.text
    # Create the list of messages. Sender can be either "user" or "assistant"
    messages = [{"sender": "user", "text": user_message}]
    base_prompt = app_prompt(new_message, messages)
    response_txt = send_message(base_prompt, AZURE_OPENAI_GPT_DEPLOYMENT, max_response_tokens)
    match = re.search('`{3}(.+?)`{3}', response_txt, re.DOTALL)
    if match:
        output = match.group(1)
    print("kusto query generated",output)
    kusto_query =output
    # Send query to AppInsights API
    query_body = {"query": kusto_query}
    query_response = requests.post(query_api, headers=query_headers, json=query_body)
    print("response",query_response)
    print("body" , query_body)
    if query_response.status_code == 200:
        query_data = json.loads(query_response.text)
        if len(query_data["tables"]) == 0 or len(query_data["tables"][0]["rows"]) == 0:
            print("Query returned no results")
        else:
            results = [row for row in query_data["tables"][0]["rows"]]
            print(f"Query returned {len(results)} rows of data")
            print(results)
    base_system_message = f"This is the kusto query given :\n\n{output}\n\nThis is result given by the query \n\n{results}\n\n All the results are based on the question asked by the user.answer the question asked by user by writing all the results to user as response of their question  "
    system_message = f"<|im_start|>system\n{base_system_message.strip()}\n<|im_end|>"
    max_response_tokens = 700
    prompt = create_prompt(system_message, messages)
    response = send_message(prompt, AZURE_OPENAI_GPT_DEPLOYMENT, max_response_tokens)
    messages.append({"sender": "assistant", "text": response})
    print_conversation(messages)
    return {"text": response}


    

